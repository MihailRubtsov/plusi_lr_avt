#include "mainwindow.h"
#include "sortwindow.h"
#include <QFileDialog>
#include <QPixmap>
#include <QLabel>
#include <QDialog>
#include <QVBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), sortWindow(nullptr)
{
    resize(250,250);
    // Создаем виджеты
    centralWidget = new QWidget(this);
    layout = new QVBoxLayout(centralWidget);
    
    selectFileButton = new QPushButton("Выбрать файл", centralWidget);
    sortButton = new QPushButton("Настроить сортировку", centralWidget);
    filePathLabel = new QLabel("Файл не выбран", centralWidget);
    //gener = new QPushButton("Сгенерировать массив", centralWidget);
    poshalka = new QPushButton("Посхалко", centralWidget);
    
    // Настройка layout
    layout->addWidget(selectFileButton);
    layout->addWidget(filePathLabel);
    layout->addWidget(sortButton);
    layout->addWidget(poshalka);
    
    setCentralWidget(centralWidget);
    
    // Подключаем сигналы
    connect(selectFileButton, &QPushButton::clicked, this, &MainWindow::selectFile);
    connect(sortButton, &QPushButton::clicked, this, &MainWindow::openSortWindow);
    connect(poshalka, &QPushButton::clicked, this, &MainWindow::showPoshalka);
    
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

void MainWindow::showPoshalka()
{
    // Укажите полный путь к вашему изображению
    QString imagePath = "/home/misha/CNPZD/plusi_lr_avt/kitik.jpg"; // Замените на реальный путь
    
    QPixmap pixmap(imagePath);
    if (!pixmap.isNull()) {
        QDialog *imageDialog = new QDialog(this);
        imageDialog->setWindowTitle("Посхалко");
        
        QLabel *imageLabel = new QLabel(imageDialog);
        imageLabel->setPixmap(pixmap.scaled(600, 400, Qt::KeepAspectRatio));
        
        QVBoxLayout *dialogLayout = new QVBoxLayout(imageDialog);
        dialogLayout->addWidget(imageLabel);
        imageDialog->setLayout(dialogLayout);
        
        imageDialog->exec(); // Показываем модальное окно
    } else {
        QMessageBox::warning(this, "Ошибка", "Не удалось загрузить изображение");
    }
}