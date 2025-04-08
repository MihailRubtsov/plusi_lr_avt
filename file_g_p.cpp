#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
#include <vector>
#include <sstream>
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

void get_massiv(string nazv_file, vector<Student>& mass, int dlina){
    string line;
    ifstream in(nazv_file);
    int i = 0;
    if (in.is_open()) {
        while (getline(in, line)) {
            vector<string> vek = razbiv_srt(line);
            mass.emplace_back(Student(vek[0], vek[1], stof(vek[2])));
            i++;
        }
    }
}

void otpr_to_file(vector<Student>& mass, int dlina){
    ofstream outt;
    outt.open("/home/misha/Desktop/otv.txt");
    string nm;
    string gr;
    string bl;

    if (outt.is_open()){
        for (int i = 0; i < dlina ; i++) {
        //arr[i].inform();
            nm = mass[i].get_name();
            gr = mass[i].get_group();
            bl = to_string(mass[i].get_ball());
            outt << nm << " " << gr << " " << bl << endl;
        }
        outt.close();
    }
}
