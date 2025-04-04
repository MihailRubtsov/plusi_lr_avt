#include "generat.h"
#include "../generatr.h"

Generat::Generat(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Генератор массива студентов");
    resize(300, 300);
    
    QVBoxLayout *layout = new QVBoxLayout(this);

    infoLabel = new QLabel("Введите количество студентов для генерации:", this);
    layout->addWidget(infoLabel);
    
    studentCountSpinBox = new QSpinBox(this);
    studentCountSpinBox->setRange(1, 1000000); 
    studentCountSpinBox->setValue(10);    
    layout->addWidget(studentCountSpinBox);
    
    generateButton = new QPushButton("Сгенерировать", this);
    layout->addWidget(generateButton);
    
    setLayout(layout);
    
    connect(generateButton, &QPushButton::clicked, this, [this](){
        int count = studentCountSpinBox->value();
        generr(count);
    });

}

int Generat::getStudentCount() const
{
    return studentCountSpinBox->value();
}