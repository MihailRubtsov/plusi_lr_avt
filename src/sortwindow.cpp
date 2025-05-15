#include "sortwindow.h"
#include <QFileInfo>
#include "fileprocessor.h"
#include "../work_with_files.h"

SortWindow::SortWindow(QWidget *parent) // окно настройки сортировки
    : QDialog(parent)
{
    resize(300, 300);
    QVBoxLayout *layout = new QVBoxLayout(this);

    fileLabel = new QLabel("Файл: не выбран", this);
    
    sortTypeCombo = new QComboBox(this); // выбор вида
    sortTypeCombo->addItem("Сортировка пузырьком");
    sortTypeCombo->addItem("Сортировка вставками");
    sortTypeCombo->addItem("Сортировка sort");
    dataTypeCombo = new QComboBox(this); // выбор как
    dataTypeCombo->addItem("По баллам");
    dataTypeCombo->addItem("По имени");
    dataTypeCombo->addItem("По группе");
    sortOrderCombo = new QComboBox(this); // выбор как 2
    sortOrderCombo->addItem("По возрастанию");
    sortOrderCombo->addItem("По убыванию");
    sortButton = new QPushButton("Выполнить сортировку", this);
    timme_sort = new QLabel("Вы пока не выполняли сортировку.", this);
    layout->addWidget(fileLabel); // добавляем в слой для отображения
    layout->addWidget(new QLabel("Тип сортировки:", this));
    layout->addWidget(sortTypeCombo);
    layout->addWidget(new QLabel("По каким данным:", this));
    layout->addWidget(dataTypeCombo);
    layout->addWidget(new QLabel("Порядок сортировки:", this));
    layout->addWidget(sortOrderCombo);
    layout->addWidget(sortButton);
    layout->addWidget(timme_sort);

    connect(sortButton, &QPushButton::clicked, this, &SortWindow::executeSort); // подключаем что должно происходить при нажатии кнопки
    setLayout(layout);
}

SortWindow::~SortWindow()
{
    
}

void SortWindow::setFilePath(const QString &path) // получаем путь к файлу
{
    filePath = path;
    fileLabel->setText("Файл: " + QFileInfo(path).fileName());
}

void SortWindow::executeSort()
{
    int sortType = sortTypeCombo->currentIndex() + 1; // параметры выбранные пользователем
    int dataType = dataTypeCombo->currentIndex() + 1;
    int sortOrder = sortOrderCombo->currentIndex() + 1;
    
    int timee = FileProcessor::processFile(filePath, sortType, dataType, sortOrder); // передаем все в функцию которая занимается сортировкой
    timme_sort->setText("Время сортировки: "+ QString::number(timee) + "ms");
}