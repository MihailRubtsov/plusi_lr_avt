#include "mainwindow.h"
#include "sortwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), sortWindow(nullptr)
{
    // Создаем виджеты
    centralWidget = new QWidget(this);
    layout = new QVBoxLayout(centralWidget);
    
    selectFileButton = new QPushButton("Выбрать файл", centralWidget);
    sortButton = new QPushButton("Настроить сортировку", centralWidget);
    filePathLabel = new QLabel("Файл не выбран", centralWidget);
    
    // Настройка layout
    layout->addWidget(selectFileButton);
    layout->addWidget(filePathLabel);
    layout->addWidget(sortButton);
    
    setCentralWidget(centralWidget);
    
    // Подключаем сигналы
    connect(selectFileButton, &QPushButton::clicked, this, &MainWindow::selectFile);
    connect(sortButton, &QPushButton::clicked, this, &MainWindow::openSortWindow);
    
    // Начальные настройки
    sortButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    if (sortWindow) delete sortWindow;
}

void MainWindow::selectFile()
{
    selectedFilePath = QFileDialog::getOpenFileName(this, "Выберите файл", "", "Текстовые файлы (*.txt)");
    if (!selectedFilePath.isEmpty()) {
        filePathLabel->setText(selectedFilePath);
        sortButton->setEnabled(true);
    }
}

void MainWindow::openSortWindow()
{
    if (selectedFilePath.isEmpty()) return;
    
    if (!sortWindow) {
        sortWindow = new SortWindow(this);
    }
    sortWindow->setFilePath(selectedFilePath);
    sortWindow->show();
}