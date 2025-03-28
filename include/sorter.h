#ifndef SORTER_H
#define SORTER_H

#include <QString>

class Sorter
{
public:
    Sorter();
    void mainn(const QString& nazv_file, int vib, int vr, int kk);
    
private:
    // Вспомогательные методы для сортировки
    void bubbleSort(/* параметры */);
    void insertionSort(/* параметры */);
    void stdSort(/* параметры */);
};

#endif // SORTER_H