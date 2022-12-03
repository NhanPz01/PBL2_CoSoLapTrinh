
#include "HotelManagement.h"
#include <iostream>
using namespace std;
int main(){
    Room a(1,10,190.2,1);
    Customer b("Nigeria","Niggeria","0101000101010","1/1/1","2/2/2",22020,1234231);
    Management c(&a,&b);
    c.print();
}