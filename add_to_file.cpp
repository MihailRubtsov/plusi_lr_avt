#include <string>
#include <iostream>
#include <fstream>
using namespace std;


void add_to_file(string strok){
    ofstream outt;
    outt.open("sortirov/prob.txt", ios::app);
    if (outt.is_open()){
        outt << endl << strok<< endl;
        outt.close();
    }

}