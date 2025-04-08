#ifndef FILE_G_P
#define FILE_G_P
using namespace std;
#include "Student.h" // Подключаем класс Student

void get_massiv(string nazv_file, vector<Student>& mass, int dlina);
void otpr_to_file(vector<Student>& mass, int dlina);

#endif