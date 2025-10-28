#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, AppCore *core) // есть подозрение, что интерфейс нужно поднимать через ленивую инициализацию, чтобы запуск был быстрый
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->core = core;
    ui->setupUi(this);

    connect(ui->newFileMenuButton, &QAction::triggered, this, MainWindow::onNewFileClicked);
     connect(ui->saveFileMenuButton, &QAction::triggered, this, MainWindow::onSaveFileClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewFileClicked() {
    this->core->getEventManager().sendMessage(AppMessage("UI", "new", 0));
}

void MainWindow::onSaveFileClicked() {
    this->core->getEventManager().sendMessage(AppMessage("UI", "save", 0));
}
