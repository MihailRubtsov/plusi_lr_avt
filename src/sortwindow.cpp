#include "sortwindow.h"
#include <QFileInfo>
#include "fileprocessor.h"
#include "../work_with_files.h"

SortWindow::SortWindow(QWidget *parent)
    : QDialog(parent)
{
    // Создаем layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    
    // Создаем элементы интерфейса
    fileLabel = new QLabel("Файл: не выбран", this);
    
    sortTypeCombo = new QComboBox(this);
    sortTypeCombo->addItem("Сортировка пузырьком");
    sortTypeCombo->addItem("Сортировка вставками");
    sortTypeCombo->addItem("Сортировка std::sort");
    
    dataTypeCombo = new QComboBox(this);
    dataTypeCombo->addItem("По баллам");
    dataTypeCombo->addItem("По имени");
    dataTypeCombo->addItem("По группе");
    
    sortOrderCombo = new QComboBox(this);
    sortOrderCombo->addItem("По возрастанию");
    sortOrderCombo->addItem("По убыванию");
    
    sortButton = new QPushButton("Выполнить сортировку", this);
    
    // Добавляем элементы в layout
    layout->addWidget(fileLabel);
    layout->addWidget(new QLabel("Тип сортировки:", this));
    layout->addWidget(sortTypeCombo);
    layout->addWidget(new QLabel("По каким данным:", this));
    layout->addWidget(dataTypeCombo);
    layout->addWidget(new QLabel("Порядок сортировки:", this));
    layout->addWidget(sortOrderCombo);
    layout->addWidget(sortButton);
    
    // Подключаем сигнал
    connect(sortButton, &QPushButton::clicked, this, &SortWindow::executeSort);
    
    setLayout(layout);
}

SortWindow::~SortWindow()
{
    // Автоматически удалятся, так как родитель this
}

void SortWindow::setFilePath(const QString &path)
{
    filePath = path;
    fileLabel->setText("Файл: " + QFileInfo(path).fileName());
}

void SortWindow::executeSort()
{
    int sortType = sortTypeCombo->currentIndex() + 1;
    int dataType = dataTypeCombo->currentIndex() + 1;
    int sortOrder = sortOrderCombo->currentIndex() + 1;
    
    FileProcessor::processFile(filePath, sortType, dataType, sortOrder);
}