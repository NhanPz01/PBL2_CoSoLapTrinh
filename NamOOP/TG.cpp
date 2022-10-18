#include "TG.h"
#include <bits/stdc++.h>
using namespace std;
TG::TG(int xA, int yA,int xB, int yB, int xC, int yC)
    : A(xA,yA), B(xB,yB), C(xC,yC)
{
    cout << "Dung TG" << endl;
}
TG::~TG(){
    cout << "Huy TG" << endl;
}
void TG::Show(){
    (this->A).Show();
    (this->B).Show();
    (this->C).Show();
}