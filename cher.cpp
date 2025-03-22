#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;




int main(){
    string st1;
    st1 = "Mama";
    string st2;
    st2 = "Amam";
    char p1;
    p1 = st1[0];
    char p2;
    p2 = st2[0];
    cout << p1 << " " << p2 << endl;

    if (p1 > p2){
        cout << st2 << " " << st1 << endl;
    }
    else{
        cout << st1 << " " << st2 << endl;
    }

    
    
    return 0;
}