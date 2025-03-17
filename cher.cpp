#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

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
    string* arr = new string[50];
    string line;
    ifstream in("prob.txt");
    int i = 0;
    if (in.is_open()){
        while (getline(in, line)){
            arr[i] = line;
            i++;
        }
    }
    for (int i = 0; i < 50; i++){
        cout << arr[i] << endl;
    }
    return 0;
}