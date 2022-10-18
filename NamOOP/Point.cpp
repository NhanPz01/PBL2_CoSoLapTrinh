#include <bits/stdc++.h>
#include "Point.h"
using namespace std;

void Point::TT(int n){
    this->xVal += n;
    this->yVal += n;
}

void Point::Show(){
    cout << "xVal=" << this->xVal << " yVal=" << this->yVal << endl;
}
Point::Point(){
    this->xVal =1;
   this->yVal =1;

}
Point::Point(int x, int y){
    cout << "Dung Point";
    this->xVal =x;
    this->yVal =y;
}
Point::Point(const Point& p){
    this->xVal = p.xVal;
    this->yVal = p.yVal;
}
Point::~Point(){
    cout<< "deleto";
}

int& Point::operator+()