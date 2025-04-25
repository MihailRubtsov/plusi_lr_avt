#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;


void generr(int kol){
    srand(time(0));
    string imia[30] = {"Маша", "Миша", "Рома", "Олег", "Сева", "Ян", "Федя", "Юра", "Света", "Лена", "Аня", "Ваня", "Даша", "Кирилл", "Настя", "Тимофей", "Зоя", "Артем", "Полина", "Глеб", "Лиза", "Максим", "Саша", "Дима", "Катя", "Никита", "Вера", "Степан", "Ульяна", "Игорь"};
    string grop[25] = {"ИДБ-1", "ИДБ-2", "ИДБ-3", "ИДБ-4", "ИДБ-5", "ПИ-101", "ПИ-102", "КБ-21", "КБ-22", "РКС-10", "РКС-11", "БИ-7", "БИ-8", "АСУ-15", "АСУ-16", "ИВТ-12", "ИВТ-13", "КГ-4", "КГ-5", "ИСП-9", "ИСП-10", "ЦП-3", "ЦП-4", "РТ-6", "РТ-7"};
    ofstream out;
    int pr;
    int vt;
    int tr;
    out.open("/home/misha/Desktop/prob.txt");
    if (out.is_open()){
        for (int i = 0; i < kol - 1; i++){
            pr = rand() % 30;
            vt = rand() % 25;
            tr = rand() % 100 + 1;
            out<< imia[pr] << " " << grop[vt] << " " << tr << endl;
        }
        pr = rand() % 30;
        vt = rand() % 25;
        tr = rand() % 100 + 1;
        out<< imia[pr] << " " << grop[vt] << " " << tr;
        out.close();
        
    }
    
}
