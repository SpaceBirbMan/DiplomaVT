#include "mainwindow.h"
#include "datamanager.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QSplashScreen>
#include <QThread>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    // создаём сплеш
    QPixmap pixmap(":/splash.png"); // или любой QPixmap
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents(); // показать немедленно

    // имитация загрузки модулей
    for (int i = 0; i <= 100; i += 25) {
        splash.showMessage(QString("Загрузка... %1%").arg(i),
                           Qt::AlignBottom | Qt::AlignCenter, Qt::white);
        QThread::msleep(300);
        a.processEvents();
    }
/////////////////////////////////////////////////
    AppCore *core = new AppCore;

    DataManager *dtm = new DataManager(core);

    core->getEventManager().subscribe("save", &DataManager::dummy, dtm);
    core->getEventManager().subscribe("new", &DataManager::dummy2, dtm);

    MainWindow mainWindow(nullptr, core);

    mainWindow.show();
/////////////////////////////////////////////////
    splash.finish(&mainWindow); // закрыть сплеш после показа окна
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "M3_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    return a.exec();
}



