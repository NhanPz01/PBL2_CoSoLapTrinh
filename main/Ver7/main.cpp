#include "RoomMng.h"
#include <iostream>
using namespace std;
int main(){
    Room c(1,1,1,1);
    {Customer *b = new Customer("Nigeria","Niggeria","0101000101010","1/1/1","2/2/2",22020,1234231);
     c.addCust(b);}
    Customer *a = new Customer("Namdz","Niggeria","0101000101010","1/1/1","2/2/2",22020,1234231);

    Room d;
    RoomMng Main;
    Main.add(&c);
    int vitri = Main.interpolationSearch(0);
    if (vitri == -1) cout << "Ko tim dc vi tri phong";
    else Main.printRoom(vitri);


}