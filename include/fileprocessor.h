#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <QString>

class FileProcessor
{
public:
    static void processFile(const QString &filePath, int sortType, int dataType, int sortOrder);
    
private:
    static void bubbleSort(/* параметры */);
    static void insertionSort(/* параметры */);
    static void stdSort(/* параметры */);
};

#endif // FILEPROCESSOR_H