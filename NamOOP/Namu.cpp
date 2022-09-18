#include <bits/stdc++.h>
#include <string.h>
#include <fstream>
using namespace std;
class Namdeptrai {
    public:
        string s;
        void Namdz();
};

void Namdeptrai::Namdz() {
    cout << s;
}

class Namu: public Namdeptrai {
    public:
        int n;
};

int main(){
    ofstream MyFile("Namu.txt");
    Namu Nam;
    Nam.s = "Gai alime dit bu";
    Nam.n = 100;
    MyFile << " " << Nam.n;
    Nam.Namdz();
    MyFile.close();
    return 0;
}