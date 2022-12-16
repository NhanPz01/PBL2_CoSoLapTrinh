#include "RoomMng.h"
#include <iostream>
using namespace std;
int main(){
    string const ROOMS = "rooms.txt";
	string const ROOMSSAVE = "rooms.txt";
	string const CUSTOMERS = "customers.txt";
	string const CUSTOMERSSAVE = "customers.txt";
    Room  *c = new Room(0,1999,1,1);
    // Room c1(0,0,0,0);
    // Room c2(1,199,1,1);
    // Room a;
    // cin >> a;
    // cout << a;
    RoomMng a;
    a.getRoomData(ROOMS, CUSTOMERS);
    a.Sort();
    a.printAll();
    a.checkIn();
    a.saveRoomData(ROOMSSAVE);
    a.saveCustomersData(CUSTOMERSSAVE);}
