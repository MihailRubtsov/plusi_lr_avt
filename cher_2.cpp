#include <iostream>
#include "add_to_file.h"
#include <string>
using namespace std;


int main(){
    string name;
    string group;
    string ball;
    cin >> name;
    cin >> group;
    cin >> ball;
    add_to_file(name, group, ball);
    return 0;
}