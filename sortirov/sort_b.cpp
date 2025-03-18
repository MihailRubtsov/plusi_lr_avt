// sort.cpp
#include "sort_b.h"
#include <algorithm> // для использования swap
using namespace std;

void sort_B(Student* mass, int size) { //сортировка пузырьком
    for (int i = 0; i < size-1; ++ i) {
        for (int j = 0; j < size-i-1; ++j) {
            if (mass[j].get_ball() > mass[j + 1].get_ball()) {
                swap(mass[j], mass[j+1]);
            }
        }
    }
}