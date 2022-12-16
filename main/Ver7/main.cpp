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
    // RoomMng a;
    // a.getRoomData(ROOMS, CUSTOMERS);
    // a.Sort();
    // a.printAll();
    // a.checkIn();
    // a.checkOut();
    // a.saveRoomData(ROOMSSAVE);
    // a.saveCustomersData(CUSTOMERSSAVE);
    RoomMng manager;
    manager.getRoomData(ROOMS, CUSTOMERS);
    bool flag = true;
    do {
        system("cls");
        cout << "----------KHACH SAN AHIHI----------" << endl
             << "(1) Hien thi tat ca cac phong" << endl
             << "(2) Hien thi phong trong" << endl
             << "(3) Them phong" << endl
             << "(4) Sua thong tin" << endl
             << "(5) Xoa phong" << endl
             << "(6) Tim phong" << endl
             << "(7) Checkin" << endl
             << "(8) Checkout" << endl
             << "(9) Thoat" << endl
             << "Lua chon : ";
        int choose;
        cin >> choose;
        switch(choose) {
            case 1:
                manager.printAll();
                break;
            case 2:
                manager.printAvailable();
                break;
            case 3:
                manager.add();
                break;
            case 4:
                cout << "Nhap so phong : " << endl;
                int s;
                cin >> s;
                manager.updateRoom(s);
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                flag = false;
                break;
        }
    } while (flag);
}
