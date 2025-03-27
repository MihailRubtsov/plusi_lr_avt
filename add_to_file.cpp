#include <string>
#include <iostream>
#include <fstream>
using namespace std;


void add_to_file(string name, string groupp, string balik){
    ofstream outt;
    outt.open("sortirov/prob.txt", ios::app);
    if (outt.is_open()){
        outt << endl << name << " " << groupp<<" " << balik;
        outt.close();
    }

}