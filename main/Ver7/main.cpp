#include "RoomMng.h"
#include <iostream>
using namespace std;
int main(){

    Customer *b = new Customer("Nigeria","Niggeria","0101000101010","1/1/1","2/2/2",22020,1234231);
    Customer *a = new Customer("Namdz","Niggeria","0101000101010","1/1/1","2/2/2",22020,1234231);
    Room c(1,1,1,1);
    Room d;
    c.addCust(b);
    c.removeCust();
    RoomMng Main;
    cout << c;
}