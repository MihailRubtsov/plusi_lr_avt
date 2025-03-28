#include "sorter.h"
#include <QFile>
#include <QTextStream>
#include <algorithm>
#include <QDebug>

Sorter::Sorter() {}

void Sorter::mainn(const QString& nazv_file, int vib, int vr, int kk)
{
    // Реализация чтения файла и сортировки
    QFile file(nazv_file);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл";
        return;
    }
    
    QTextStream in(&file);
    // Чтение данных и сортировка в зависимости от параметров
    
    // Примерная логика:
    switch(vib) {
    case 1: bubbleSort(/* параметры */); break;
    case 2: insertionSort(/* параметры */); break;
    case 3: stdSort(/* параметры */); break;
    }
    
    file.close();
    
    // Запись отсортированных данных обратно в файл
}