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
    int vr;
    cout << "напиши 1 чтобы по баллам , 2 чтобы по имени и 3 по группе " << endl;
    cin >> vr;
    int kk;
    cout << "напиши 1 чтобы от меньшего к большему и 2 от большему к меньшему " << endl;
    cin >> kk;
    mainn(name, vib, vr, kk);
    return 0;
}