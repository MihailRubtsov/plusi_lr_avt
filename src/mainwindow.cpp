#include "mainwindow.h"
#include "sortwindow.h"
#include <QFileDialog>
#include <QPixmap>
#include <QLabel>
#include <QDialog>
#include <QVBoxLayout>
#include <QMessageBox>
#include "generat.h"
#include "addstudentwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), sortWindow(nullptr), generatWindow(nullptr), addStudentWindow(nullptr)
{
    resize(300, 300);
    
    // Создаем виджеты
    centralWidget = new QWidget(this);
    layout = new QVBoxLayout(centralWidget);
    
    selectFileButton = new QPushButton("Выбрать файл", centralWidget);
    sortButton = new QPushButton("Настроить сортировку", centralWidget);
    filePathLabel = new QLabel("Файл не выбран", centralWidget);
    gener = new QPushButton("Генератор массива", centralWidget);
    poshalka = new QPushButton("Посхалко", centralWidget);
    dobavlenie = new QPushButton("Добавление в файл", centralWidget);

    
    // Настройка layout
    layout->addWidget(selectFileButton);
    layout->addWidget(filePathLabel);
    layout->addWidget(sortButton);
    layout->addWidget(poshalka);
    layout->addWidget(gener);
    layout->addWidget(dobavlenie);
    
    setCentralWidget(centralWidget);
    
    // Подключаем сигналы
    connect(selectFileButton, &QPushButton::clicked, this, &MainWindow::selectFile);
    connect(sortButton, &QPushButton::clicked, this, &MainWindow::openSortWindow);
    connect(poshalka, &QPushButton::clicked, this, &MainWindow::showPoshalka);
    connect(gener, &QPushButton::clicked, this, &MainWindow::open_generator);
    connect(dobavlenie, &QPushButton::clicked, this, &MainWindow::openAddStudentWindow);
    
    // Начальные настройки
    sortButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    if (sortWindow) delete sortWindow;
    if (generatWindow) delete generatWindow;
    if (addStudentWindow) delete addStudentWindow;
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

void MainWindow::open_generator()
{
    if (!generatWindow) {
        generatWindow = new Generat(this);
    }
    generatWindow->show();
}

void MainWindow::showPoshalka()
{
    QPixmap pixmap(POSHALKA_IMAGE_PATH);
    if (!pixmap.isNull()) {
        QDialog *imageDialog = new QDialog(this);
        imageDialog->setWindowTitle("Посхалко");
        
        QLabel *imageLabel = new QLabel(imageDialog);
        imageLabel->setPixmap(pixmap.scaled(600, 400, Qt::KeepAspectRatio));
        
        QVBoxLayout *dialogLayout = new QVBoxLayout(imageDialog);
        dialogLayout->addWidget(imageLabel);
        imageDialog->setLayout(dialogLayout);
        
        imageDialog->exec();
    } else {
        QMessageBox::warning(this, "Ошибка", "Не удалось загрузить изображение");
    }
}

void MainWindow::openAddStudentWindow()
{
    if (!addStudentWindow) {
        addStudentWindow = new AddStudentWindow(this);
    }
    addStudentWindow->show();
}