#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <QString>

class FileProcessor
{
public:
    static int processFile(const QString &filePath, int sortType, int dataType, int sortOrder);
};

#endif 