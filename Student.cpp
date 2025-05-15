// Student.cpp
#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string pname, string pgroup, float psr_ball) { // класс студент, именно он создается при считывании файла
    name = pname;
    GRoup = pgroup;
    sr_ball = psr_ball;
}

void Student::inform() {
    cout << name << " " << GRoup << " " << sr_ball << endl;
}

float Student::get_ball() {
    return sr_ball;
}

string Student::get_name() {
    return name;
}

string Student::get_group() {
    return GRoup;
}



