
#include "HotelMng.h"
#include <iostream>
using namespace std;
int main(){
    Customer b("Nigeria","Niggeria","0101000101010","1/1/1","2/2/2",22020,1234231);
    Customer a;
    Room c(1,1,1,1);
    Room d;
    d=c;
    a = b;
    cout << a << d;
}