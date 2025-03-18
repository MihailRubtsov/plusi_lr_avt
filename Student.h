// Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
public:
    string name;
    string GRoup;
    float sr_ball;

    Student(string pname = "None", string pgroup = "None", float psr_ball = 0.0);
    void inform();
    float get_ball();
    string get_name();
    string get_group();
};

#endif