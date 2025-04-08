#include <iostream>
#include <string>
#include "add_to_file.h"
#include "work_with_files.h"
using namespace std;

int main(){
    string nazv_file;
    cout << "Введите название файла: " << endl;
    cin >> nazv_file;
    cout << "Если хотите добавить строку то напишите 1." << endl;
    int nap;
    cin >> nap;
    if (nap == 1){
        cout << "Напишите строку" << endl;
        string nmmm;
        string grrr;
        string bll;
        cin >> nmmm;
        cin >> grrr;
        cin >> bll;
        add_to_file(nmmm, grrr, bll);
    }
    int vib;
    cout << "Выберете сортировку которой хотите сортировать массив.\n1 - сортировка пузырьком\n2 - сортировка вставками\n3 - сортировка sort от C++" << endl;
    cin >> vib;
    string name;
    name = "sortirov/prob.txt";
    int vr;
    cout << "напиши 1 чтобы по баллам , 2 чтобы по имени и 3 по группе " << endl;
    cin >> vr;
    int kk;
    cout << "напиши 1 чтобы от меньшего к большему и 2 от большему к меньшему " << endl;
    cin >> kk;
    mainn(nazv_file, vib, vr, kk);
    
    return 0;
}