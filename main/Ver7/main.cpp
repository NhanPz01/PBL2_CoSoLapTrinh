#include "RoomMng.h"
#include <iostream>
using namespace std;
int main(){
    Room c(1,1,1,1);
    Room c1(0,0,0,0);
    Room c2(1,199,1,1);


    Room d;
    RoomMng Main;
    Main.add(&c);
    Main.add(&c1);
    Main.add(&c2);
    Main.printBy();


}