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

MainWindow::MainWindow(QWidget *parent) // самое главное окно
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

    layout->addWidget(selectFileButton);
    layout->addWidget(filePathLabel);
    layout->addWidget(sortButton);
    layout->addWidget(poshalka);
    layout->addWidget(gener);
    layout->addWidget(dobavlenie);
    setCentralWidget(centralWidget);
    
    connect(selectFileButton, &QPushButton::clicked, this, &MainWindow::selectFile); // говорим кнопкам что должно происходить при их нажатии
    connect(sortButton, &QPushButton::clicked, this, &MainWindow::openSortWindow);
    connect(poshalka, &QPushButton::clicked, this, &MainWindow::showPoshalka);
    connect(gener, &QPushButton::clicked, this, &MainWindow::open_generator);
    connect(dobavlenie, &QPushButton::clicked, this, &MainWindow::openAddStudentWindow);
    sortButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    if (sortWindow) delete sortWindow;
    if (generatWindow) delete generatWindow;
    if (addStudentWindow) delete addStudentWindow;
}

void MainWindow::selectFile() // функция для выбора файла
{
    selectedFilePath = QFileDialog::getOpenFileName(this, "Выберите файл", "", "Текстовые файлы (*.txt)");
    if (!selectedFilePath.isEmpty()) {
        filePathLabel->setText(selectedFilePath);
        sortButton->setEnabled(true);
    }
}

void MainWindow::openSortWindow() // открытие сортировочного окна
{
    if (selectedFilePath.isEmpty()) return;
    if (!sortWindow) {
        sortWindow = new SortWindow(this);
    }
    sortWindow->setFilePath(selectedFilePath);
    sortWindow->show();
}

void MainWindow::open_generator() // открытие окна генерации
{
    if (!generatWindow) {
        generatWindow = new Generat(this);
    }
    generatWindow->show();
}

void MainWindow::showPoshalka() // фото котика
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
    }
}

void MainWindow::openAddStudentWindow() // открытие окна добавления студента
{
    if (!addStudentWindow) {
        addStudentWindow = new AddStudentWindow(this);
    }
    addStudentWindow->show();
}