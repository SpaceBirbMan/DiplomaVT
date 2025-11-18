#include "uirenderer.h"

///////////////////////////////////////////////////////////////
//  helpers
///////////////////////////////////////////////////////////////

static QBoxLayout* makeLayout(GroupSortType sort) {
    return (sort == VBox)
    ? static_cast<QBoxLayout*>(new QVBoxLayout)
    : static_cast<QBoxLayout*>(new QHBoxLayout);
}

///////////////////////////////////////////////////////////////
//  Render dispatcher
///////////////////////////////////////////////////////////////

QWidget* UiRenderer::renderElement(UiElement* elem) {

    if (auto g = dynamic_cast<UiGroup*>(elem))
        return renderGroup(g);

    if (auto pg = dynamic_cast<UiPage*>(elem))
        return renderPage(pg);

    if (auto c = dynamic_cast<UiContainer*>(elem))
        return renderContainer(c);

    if (auto t = dynamic_cast<UiTitle*>(elem)) {
        QLabel* l = new QLabel(QString::fromStdString(t->text));
        QFont f = l->font();
        if (t->format == Italic) f.setItalic(true);
        if (t->format == Bold) f.setBold(true);
        if (t->format == Underline) f.setUnderline(true);
        l->setFont(f);
        return l;
    }

    if (auto b = dynamic_cast<UiButton*>(elem)) {
        QPushButton* btn = new QPushButton(QString::fromStdString(b->text));
        if (b->onClick) {
            QObject::connect(btn, &QPushButton::clicked,
                             [cb = b->onClick]() { cb(); });
        }
        return btn;
    }

    if (auto tb = dynamic_cast<UiToggleableButton*>(elem)) {
        QPushButton* btn = new QPushButton(QString::fromStdString(tb->text));
        btn->setCheckable(true);
        btn->setChecked(tb->active);

        if (tb->onToggle) {
            QObject::connect(btn, &QPushButton::toggled,
                             [cb = tb->onToggle](bool v) { cb(v); });
        }
        return btn;
    }

    if (auto cb = dynamic_cast<UiCheckBox*>(elem)) {
        QCheckBox* ch = new QCheckBox(QString::fromStdString(cb->text));
        ch->setChecked(cb->active);
        if (cb->onToggle)
            QObject::connect(ch, &QCheckBox::toggled,
                             [cbfn = cb->onToggle](bool v){ cbfn(v); });
        return ch;
    }

    if (auto in = dynamic_cast<UiInputField*>(elem)) {
        QLineEdit* le = new QLineEdit;
        le->setPlaceholderText(QString::fromStdString(in->hint));
        le->setText(QString::fromStdString(in->value));
        if (in->inputType == HIDDENTEXT) le->setEchoMode(QLineEdit::Password);

        if (in->onTextChanged) {
            QObject::connect(le, &QLineEdit::textChanged,
                             [cb = in->onTextChanged](const QString& v){
                                 cb(v.toStdString());
                             });
        }
        return le;
    }

    if (auto sp = dynamic_cast<UiSpinField*>(elem)) {

        if (!sp->isFloat) {
            QSpinBox* sb = new QSpinBox;
            sb->setRange(sp->minValue, sp->maxValue);
            sb->setValue(sp->intValue);

            if (sp->onValueChanged)
                QObject::connect(sb, &QSpinBox::valueChanged,
                                 [cb = sp->onValueChanged](int v){ cb(v); });

            return sb;
        } else {
            QDoubleSpinBox* ds = new QDoubleSpinBox;
            ds->setRange(sp->minValue, sp->maxValue);
            ds->setValue(sp->intValue);

            if (sp->onValueChanged)
                QObject::connect(ds, &QDoubleSpinBox::valueChanged,
                                 [cb = sp->onValueChanged](double v){ cb((int)v); });

            return ds;
        }
    }

    if (auto sl = dynamic_cast<UiSlider*>(elem)) {
        QSlider* s = new QSlider(Qt::Horizontal);
        s->setRange(sl->minValue, sl->maxValue);
        s->setValue(sl->value);

        if (sl->onSlide)
            QObject::connect(s, &QSlider::valueChanged,
                             [cb = sl->onSlide](int v){ cb(v); });

        return s;
    }

    if (auto dl = dynamic_cast<UiDial*>(elem)) {
        QDial* d = new QDial;
        d->setRange(dl->minValue, dl->maxValue);
        d->setValue(dl->value);

        if (dl->onSlide) {
            QObject::connect(d, &QDial::valueChanged,
                             [cb = dl->onSlide](int v){ cb(v); });
        }

        return d;
    }

    if (auto pb = dynamic_cast<UiProgressBar*>(elem)) {
        QProgressBar* p = new QProgressBar;
        p->setRange(pb->minValue, pb->maxValue);
        p->setValue(pb->value);
        // ориентации можно добавить позже
        return p;
    }

    if (auto cbx = dynamic_cast<UiComboBox*>(elem)) {
        QComboBox* box = new QComboBox;
        for (const auto& it : cbx->items)
            box->addItem(QString::fromStdString(it));

        box->setCurrentIndex(cbx->currentIndex);

        if (cbx->onSelect) {
            QObject::connect(box, QOverload<int>::of(&QComboBox::currentIndexChanged),
                             [cb = cbx->onSelect](int v){ cb(v); });
        }
        return box;
    }

    return new QWidget;  // fallback
}

///////////////////////////////////////////////////////////////
//  Containers
///////////////////////////////////////////////////////////////

QWidget* UiRenderer::renderContainer(UiContainer* container) {
    QWidget* w = new QWidget;
    auto lay = new QVBoxLayout;
    w->setLayout(lay);

    for (auto& ch : container->children) {
        QWidget* child = renderElement(ch.get());
        lay->addWidget(child);
    }

    return w;
}

QWidget* UiRenderer::renderGroup(UiGroup* group) {
    QWidget* w = new QWidget;
    auto lay = makeLayout(group->sort);
    w->setLayout(lay);

    for (auto& ch : group->children)
        lay->addWidget(renderElement(ch.get()));

    return w;
}

QWidget* UiRenderer::renderPage(UiPage* page) {
    // страница сама по себе = контейнер +
    // заголовок будет handled в TabWidget
    return renderContainer(page);
}

///////////////////////////////////////////////////////////////
//  Root renderer into QTabWidget
///////////////////////////////////////////////////////////////

void UiRenderer::renderToTabWidget(UiContainer* root, QTabWidget* tabTarget) {
    tabTarget->clear();

    for (auto& ch : root->children) {
        if (auto page = dynamic_cast<UiPage*>(ch.get())) {
            QWidget* content = renderPage(page);
            tabTarget->insertTab(page->index, content,
                                 QString::fromStdString(page->title));
        }
    }
}
