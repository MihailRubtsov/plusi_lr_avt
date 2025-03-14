#include <iostream>
#include <string>
using namespace std;

int find_p(int list[], int start_p, int listLength)  
{
    int pos = start_p; 
    for (int i = start_p; i < listLength; i++) 
    {
        if (list[i] < list[pos])
        pos = i; 
    }
    return pos; 
}

void selectionSort(int list[], int len) // сортировка вставками
{
    for (int i = 0; i < len; i++) 
    {
        int smalls_p = find_p(list, i, len);
        swap(list[i], list[smalls_p]);
    }
}


void sort_plusi(int list[], int len){
    

}


void sort_B(int* mass, int size) { //сортировка пузырьком
    for (int i = 0; i < size-1; ++ i) {
        for (int j = 0; j < size-i-1; ++j) {
            if (mass[j] > mass[j + 1]) {
                swap(mass[j], mass[j+1]);
            }
        }
    }
}


int main(){
    return 0;
}

