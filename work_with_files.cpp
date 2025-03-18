#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Student.h"
#include "sortirov/sort_v.h"
#include "sortirov/sort_b.h"
#include <chrono>

using namespace std;

vector<string> razbiv_srt(string strr) {
    istringstream iss(strr);
    vector<string> tokens;
    string token;
    while (getline(iss, token, ' ')) {
        tokens.push_back(token);
    }
    if (tokens.size() < 3) {
        cout << "В строке меньше трех слов!" << endl;
        return tokens;
    }
    return tokens;
}

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
    cout << dlin_file() << endl;
    int dlin = dlin_file();
    Student* arr = new Student[dlin];
    string line;
    ifstream in("sortirov/prob.txt");
    int i = 0;
    if (in.is_open()) {
        while (getline(in, line)) {
            vector<string> vek = razbiv_srt(line);
            arr[i] = Student(vek[0], vek[1], stof(vek[2]));
            i++;
        }
    }
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
    for (int i = 0; i < dlin ; i++) {
        //arr[i].inform();
    }
    delete[] arr;
    return 0;
}