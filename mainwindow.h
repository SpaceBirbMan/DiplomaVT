#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "appcore.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, AppCore* appCorePointer = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    AppCore* core;

    void showCacheErrorMessage();

private slots:
    void onNewFileClicked();
    void onSaveFileClicked();
};
#endif // MAINWINDOW_H
