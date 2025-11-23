#ifndef UIRENDERER_H
#define UIRENDERER_H

#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QSlider>
#include <QProgressBar>
#include <QComboBox>
#include <QDial>
#include <QSpinBox>
#include <QDoubleSpinBox>

#include "AbstractUiNodes.h"

class UiRenderer {
public:
    static QWidget* renderElement(UiElement* elem);
    static QWidget* renderContainer(UiContainer* container);
    static QWidget* renderGroup(UiGroup* group);
    static QWidget* renderPage(UiPage* page);

    static void renderToTabWidget(std::shared_ptr<UiPage> root, QTabWidget* tabTarget);
};

#endif // UIRENDERER_H
