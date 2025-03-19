#include <iostream>
#include <string>
#include "work_with_files.h"
using namespace std;

int main(){
    int vib;
    cout << "Выберете сортировку которой хотите сортировать массив.\n1 - сортировка пузырьком\n2 - сортировка вставками" << endl;
    cin >> vib;
    string name;
    name = "sortirov/prob.txt";
    mainn(name, vib, 0);
    return 0;
}