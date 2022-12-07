#include "RoomMng.h"
#include <iostream>
using namespace std;
int main(){
    Customer b("Nigeria","Niggeria","0101000101010","1/1/1","2/2/2",22020,1234231);
    Customer a;
    Room c(1,1,1,1);
    Room d;
    RoomMng Main;
    c.addCust(&b);
    d=c;
    a = b;
    Main.add(&c);
    Main.add(&d);
    Main.printAll();
}