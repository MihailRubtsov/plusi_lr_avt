#include "sort_v.h"
#include <algorithm> // для использования swap
using namespace std;


int find_p(Student list[], int start_p, int listLength, int vibbr, int kak)  
{
    
    int pos = start_p; 
    switch(vibbr){
        case 1: // по баллу
        if (kak == 1){ // от меньшего к большему
            for (int i = start_p; i < listLength; i++) 
            {
                if (list[i].get_ball() < list[pos].get_ball())
                pos = i; 
            }
        }
        else{ // от большего к меньшему
            for (int i = start_p; i < listLength; i++) 
            {
                if (list[i].get_ball() > list[pos].get_ball())
                pos = i; 
            }
        }
        break;
        case 2: // по имени
        if (kak == 1){ // по алфавитному порядку
            for (int i = start_p; i < listLength; i++) 
            {
                if (list[i].get_name() < list[pos].get_name())
                pos = i; 
            }
        }
        else{ // обратный алфавитному
            for (int i = start_p; i < listLength; i++) 
            {
                if (list[i].get_name() > list[pos].get_name())
                pos = i; 
            }
        }
        break;
        case 3: // по группе
        if (kak == 1){ // от меньшей к большей
            for (int i = start_p; i < listLength; i++) 
            {
                if (list[i].get_group() < list[pos].get_group())
                pos = i; 
            }
        }
        else{ // от большей к меньшей
            for (int i = start_p; i < listLength; i++) 
            {
                if (list[i].get_group() > list[pos].get_group())
                pos = i; 
            }
        }
        break;
    }
    return pos; 
}

void selectionSort(Student list[], int len, int vr, int kk) // сортировка вставками
{
    for (int i = 0; i < len; i++) 
    {
        int smalls_p = find_p(list, i, len, vr,kk);
        swap(list[i], list[smalls_p]);
    }
}