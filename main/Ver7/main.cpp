#include "RoomMng.h"
#include <iostream>
using namespace std;
int main(){
    Room c(0,0,0,0);
    {Customer *b = new Customer("Nigeria","Niggeria","0101000101010","1/1/1","2/2/2",22020,1234231);
     c.addCust(b);}
    Customer *a = new Customer("Namdz","Niggeria","0101000101010","1/1/1","2/2/2",22020,1234231);

    Room d;
    RoomMng Main;
    Main.add(&c);
    Main.updateRoom(0);
    Main.printAvailable();
}