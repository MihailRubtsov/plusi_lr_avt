#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Student.h"
#include "sortirov/sort_v.h"
#include "sortirov/sort_b.h"
#include "file_g_p.h"
#include "sortirov/sich_sort.h"
#include <chrono>

using namespace std;

int dlin_file(string name_f) {
    int dl {0};
    string line;
    ifstream in(name_f);

    if (in.is_open()) {
        while (getline(in, line)) {
            dl++;
        }
    }
    return dl;
}


int mainn(string name_file, int vibb, int vib_k, int kk) {
    int dlin = dlin_file(name_file);
    Student* arr = new Student[dlin];
    get_massiv(arr, dlin);
    

    chrono::time_point<chrono::high_resolution_clock> start, end;
    chrono::milliseconds duration;
    switch (vibb)
    {
    case 1 : // если сортировка пузырьком
        start = chrono::high_resolution_clock::now();
        sort_B(arr, dlin, vib_k , kk);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Время выполнения сортировки: " << duration.count() << " мс" << endl;
        cout << "сортировка пузырьком" << endl;
        break;
    case 2: // сортировка вставками
        start = chrono::high_resolution_clock::now();
        selectionSort(arr, dlin, vib_k , kk);
        end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Время выполнения сортировки: " << duration.count() << " мс" <<endl;
        cout << "сортировка вставками" << endl;
        break;
    case 3:
    start = chrono::high_resolution_clock::now();
    sorti(arr, dlin, vib_k , kk);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Время выполнения сортировки: " << duration.count() << " мс" << endl;
    cout << "сортировка sort от C++" << endl;
    break;
    }
    otpr_to_file(arr, dlin);
    delete[] arr;
    return 0;
}


