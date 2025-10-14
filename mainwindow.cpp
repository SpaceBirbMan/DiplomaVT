#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) // есть подозрение, что интерфейс нужно поднимать через ленивую инициализацию, чтобы запуск был быстрый
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    connect(ui->newFileMenuButton, &QAction::triggered, this, MainWindow::onNewFileClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewFileClicked() { // todo: Переписать

}
