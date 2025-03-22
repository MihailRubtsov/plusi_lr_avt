// sort.cpp
#include "sort_b.h"
#include <algorithm> // для использования swap
using namespace std;

void sort_B(Student* mass, int size, int vibbr, int kak) { //сортировка пузырьком
    switch(vibbr){
        case 1: // сортировка по баллам
            for (int i = 0; i < size-1; ++ i) {
                for (int j = 0; j < size-i-1; ++j) {
                    if (kak == 1){
                        if (mass[j].get_ball() > mass[j + 1].get_ball()) {
                            swap(mass[j], mass[j+1]);
                        }
                    }
                    else {
                        if (mass[j].get_ball() < mass[j + 1].get_ball()) {
                            swap(mass[j], mass[j+1]);
                        }
                    }
                }
            }
            break;
        
        case 2: // сортировка по имени
            for (int i = 0; i < size-1; ++ i) {
                for (int j = 0; j < size-i-1; ++j) {
                    if (kak == 1){
                        if (mass[j].get_name() > mass[j + 1].get_name()) {
                            swap(mass[j], mass[j+1]);
                        }
                    }
                    else {
                        if (mass[j].get_name() < mass[j + 1].get_name()) {
                           swap(mass[j], mass[j+1]);
                        }
                    }
                }
            }
            break;

        case 3: // сортировка по группе
            for (int i = 0; i < size-1; ++ i) {
                for (int j = 0; j < size-i-1; ++j) {
                    if (kak == 1){
                        if (mass[j].get_group() > mass[j + 1].get_group()) {
                            swap(mass[j], mass[j+1]);
                        }
                    }
                    else {
                        if (mass[j].get_group() < mass[j + 1].get_group()) {
                           swap(mass[j], mass[j+1]);
                        }
                    }
                }
            }
            break;
    }
    
}