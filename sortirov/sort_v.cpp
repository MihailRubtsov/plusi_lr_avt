#include "sort_v.h"
#include <algorithm> // для использования swap
using namespace std;


int find_p(Student list[], int start_p, int listLength)  
{
    int pos = start_p; 
    for (int i = start_p; i < listLength; i++) 
    {
        if (list[i].get_ball() < list[pos].get_ball())
        pos = i; 
    }
    return pos; 
}

void selectionSort(Student list[], int len) // сортировка вставками
{
    for (int i = 0; i < len; i++) 
    {
        int smalls_p = find_p(list, i, len);
        swap(list[i], list[smalls_p]);
    }
}