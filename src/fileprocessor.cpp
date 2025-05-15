#include "fileprocessor.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <algorithm>
#include <chrono>
#include "../work_with_files.h"




int FileProcessor::processFile(const QString &filePath, int sortType, int dataType, int sortOrder) // эта функция вызывается при нажатие кнопки сортировки
{
    auto start = std::chrono::high_resolution_clock::now(); // начало работы сортировки
    mainn(filePath.toStdString(), sortType, dataType, sortOrder); // вызов функции с сортировками в которой и проходит сама сортировка
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    int kolvo = duration.count(); // получаем время сортировки
    return kolvo;
}
