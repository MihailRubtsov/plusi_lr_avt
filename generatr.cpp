#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;



int main(){
    string imia[10] = {"Маша", "Миша", "Рома", "Олег", "Сева", "Ян", "Федя", "Юра", "Света", "Лена"};
    string grop[5] = {"ИДБ-1","ИДБ-2","ИДБ-3","ИДБ-4","ИДБ-5"};
    ofstream out;
    int pr;
    int vt;
    int tr;
    out.open("prob.txt");
    if (out.is_open()){
        for (int i = 0; i < 100000 ; i ++){
            pr = rand() % 10;
            vt = rand() % 5;
            tr = rand() % 100 + 1;
            out<< imia[pr] << " " << grop[vt] << " " << tr << endl;
        }
        
    }
    
    return 0;
}