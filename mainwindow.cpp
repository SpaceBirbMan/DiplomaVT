#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QQuickView>

QQuickView* view = new QQuickView(); // через эту тему лучше пойдёт рендер
// надо размещать отдельно, должно пойти с любым rend-back

MainWindow::MainWindow(QWidget *parent, AppCore *core) // есть подозрение, что интерфейс нужно поднимать через ленивую инициализацию, чтобы запуск был быстрый
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->core = core;
    ui->setupUi(this);

    core->getEventManager().subscribe("cache_err", &MainWindow::showCacheErrorMessage, this);
    core->getEventManager().subscribe("send_control_table", &MainWindow::setControlsTable, this);

    connect(ui->newFileMenuButton, &QAction::triggered, this, MainWindow::onNewFileClicked);
    connect(ui->saveFileMenuButton, &QAction::triggered, this, MainWindow::onSaveFileClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showCacheErrorMessage() {
    std::cout << "Cache doesn't exists, idi peredelivay" << std::endl;
}

void MainWindow::onNewFileClicked() {
    this->core->getEventManager().sendMessage(AppMessage("UI", "new", 0));
}

void MainWindow::onSaveFileClicked() {
    this->core->getEventManager().sendMessage(AppMessage("UI", "save", 2147483646));
}

void MainWindow::setControlsTable(std::unordered_map<std::string, std::string> table) {
    QTableWidget* tw = ui->tableWidget;

    tw->clear(); // очищает данные и заголовки
    tw->setColumnCount(2);
    tw->setHorizontalHeaderLabels({"Контроллер модели", "Контроллер устройства"});
    tw->setRowCount(static_cast<int>(table.size()));

    int i = 0;
    for (const auto& pair : table) {
        tw->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(pair.first)));
        tw->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(pair.second)));
        ++i;
    }

    tw->resizeColumnsToContents();
}

void MainWindow::initDynamicUi() {
    //UiContainer* root = core->getUiRoot();
    // ui не тянется из ядра, он тянется из менеджеров модулей

    //UiRenderer::renderToTabWidget(root, ui->leftPanel);
}
