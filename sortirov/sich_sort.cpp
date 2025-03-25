#include <iostream>
#include <string>
#include <algorithm>
#include "sich_sort.h"
#include "../Student.h"
using namespace std;



bool compare_two(Student& a, Student& b, int vibr, int kakak) { 
    switch(vibr){
        case 1: // по среднему баллу
            if (kakak == 1) {
                return a.get_ball() < b.get_ball();
            }
            else{
                return a.get_ball() > b.get_ball();
            }
        case 2: // по имени
            if (kakak == 1) {
                return a.get_name() < b.get_name();
            }
            else {
                return a.get_name() > b.get_name();
            }
        case 3: // по группе
            if (kakak == 1) {
                return a.get_group() < b.get_group();
            }
            else {
                return a.get_group() > b.get_group();
            }
        default:
            return false;
    }
}

// Функция сортировки массива студентов
void sorti(Student* mass, int size, int vibb, int kak) {
    std::sort(mass, mass + size, 
        [vibb, kak](Student& a, Student& b) {
            return compare_two(a, b, vibb, kak);
        }
    );
}

