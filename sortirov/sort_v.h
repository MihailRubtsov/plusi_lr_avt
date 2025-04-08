// sort.h
#ifndef SORT_V
#define SORT_V
using namespace std;
#include <vector>
#include "../Student.h" // Подключаем класс Student


int find_p(vector<Student>& list, int start_p, int listLength, int vibbr, int kak);
void selectionSort(vector<Student>& list, int len, int vr, int kk);

#endif