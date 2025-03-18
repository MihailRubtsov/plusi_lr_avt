#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Student.h"
#include "sortirov/sort_v.h"
#include "sortirov/sort_b.h"
#include "file_g_p.h"
#include <chrono>

using namespace std;

int dlin_file() {
    int dl {0};
    string line;
    ifstream in("sortirov/prob.txt");

    if (in.is_open()) {
        while (getline(in, line)) {
            dl++;
        }
    }
    return dl;
}


int main() {
    int dlin = dlin_file();
    Student* arr = new Student[dlin];
    get_massiv(arr, dlin);
    int vib;
    cout << "Выберете сортировку которой хотите сортировать массив.\n1 - сортировка пузырьком\n2 - сортировка вставками" << endl;
    cin >> vib;

    chrono::time_point<chrono::high_resolution_clock> start, end;
    chrono::milliseconds duration;
    switch (vib)
    {
    case 1 :
        start = chrono::high_resolution_clock::now();
        sort_B(arr, dlin);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Время выполнения сортировки: " << duration.count() << " мс" << endl;
        cout << "сортировка пузырьком" << endl;
        break;
    case 2:
        start = chrono::high_resolution_clock::now();
        selectionSort(arr, dlin);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Время выполнения сортировки: " << duration.count() << " мс" <<endl;
        cout << "сортировка вставками" << endl;
        break;

    }
    otpr_to_file(arr, dlin);
    delete[] arr;
    return 0;
}