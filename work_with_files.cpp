#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std; 
class Student {
public:
    string name;
    string GRoup;
    float sr_ball;
    Student(string pname, string pgroup, float psr_ball){
        name = pname;
        GRoup = pgroup;
        sr_ball = psr_ball;
    }
    Student(){
        name = "None";
        GRoup = "None";
        sr_ball = 0.0;
    }
    void inform(){
        cout << name << " " << GRoup << " " << sr_ball<< endl;

    }

};
vector<string> razbiv_srt(string strr){
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



int main(){
    int dlin{50};
    //cin >> dlin;
    //string* arr_str = new string[50];
    Student* arr = new Student[dlin];
    string line;
    ifstream in("prob.txt");
    int i = 0;
    if (in.is_open()){
        while (getline(in, line)){
            vector<string> vek = razbiv_srt(line);
            arr[i] = Student(vek[0], vek[1], stof(vek[2]));
            i++;
        }
    }



    

    for (int i = 0; i < dlin ; i++){
        arr[i].inform();
    }
    delete[] arr;


    return 0;
}