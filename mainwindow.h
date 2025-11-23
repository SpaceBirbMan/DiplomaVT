#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "appcore.h"
#include <QTableWidget>
#include "uirenderer.h"

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
    void setControlsTable(std::unordered_map<std::string, std::string> table);
    void initDynamicUi(std::shared_ptr<UiPage> root);

private slots:
    void onNewFileClicked();
    void onSaveFileClicked();

};
#endif // MAINWINDOW_H
