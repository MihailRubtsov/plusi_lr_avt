#include "fileprocessor.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <algorithm>
#include <chrono>
#include "../work_with_files.h"




int FileProcessor::processFile(const QString &filePath, int sortType, int dataType, int sortOrder) // эта функция вызывается при нажатие кнопки сортировки
{
    auto start = std::chrono::high_resolution_clock::now();
    mainn(filePath.toStdString(), sortType, dataType, sortOrder);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    int kolvo = duration.count();
    
    qDebug() << "Время выполнения сортировки:" << duration.count() << "мс";
    return kolvo;
}
