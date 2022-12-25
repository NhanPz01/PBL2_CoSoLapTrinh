#include <windows.h>
#include <cwchar>
#include "RoomMng.h"
#include <iostream>
using namespace std;
int main(){
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 30;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    cout << "Font: Consolas, Size: 24\n";
    HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 900, 800, TRUE);
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut,  BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
    string const ROOMS = "rooms.txt";
	string const ROOMSSAVE = "rooms.txt";
	string const CUSTOMERS = "customers.txt";
	string const CUSTOMERSSAVE = "customers.txt";
    Room  *c = new Room(0,1999,1,1);
    RoomMng manager;
    manager.getRoomData(ROOMS, CUSTOMERS);
    manager.Sort();
    bool flag = true;
    do {
        system("cls");
        cout << "-----------------------KHACH SAN AHIHI----------------------" << endl;
        cout << "\t(1) Hien thi tat ca cac phong" << endl;
        cout << "\t(2) Hien thi phong trong" << endl;
        cout << "\t(3) Them phong" << endl;
        cout << "\t(4) Sua thong tin" << endl;
        cout << "\t(5) Xoa phong" << endl;
        cout << "\t(6) Tim phong" << endl;
        cout << "\t(7) Checkin" << endl;
        cout << "\t(8) Checkout" << endl;
        cout << "\t(9) Thoat" << endl;
        cout << "LUA CHON: ";
        int choose;
        cin >> choose;
        switch(choose) {
            case 1 : {
                manager.printAll();
                break;
            }
            case 2 : {
                manager.printAvailable();
                break;
            }
            case 3 : {
                manager.add();
                manager.Sort();
                break;
            }
            case 4 : {
                system("cls");
                cout << "NHAP SO PHONG: ";
                int s;
                cin >> s;
                system("cls");
                manager.updateRoom(s);
                break;
            }
            case 5 : {
                system("cls");
                cout << "--------------------------XOA PHONG--------------------------";
                cout << "NHAP SO PHONG: ";
                int s;
                cin >> s;
                manager.removeAt(s);
                system("pause");
                system("cls");
                break;
            }
            case 6 : {
                system("cls");
                cout << "-----------------------TIM KIEM PHONG-----------------------" << endl;
                cout << "NHAP SO PHONG: ";
                int s;
                cin >> s;
                int location = manager.interpolationSearch(s);
                if (location != -1)
                {
                    manager.printRoom(location);
                }
                else
                {
                    cout << "PHONG KHONG TON TAI:" << endl;
                    while(location == -1)
                    {
                        cout << "VUI LONG NHAP LAI: ";
                        cin >> s;
                        location = manager.interpolationSearch(s);
                    }
                    cout << "\nPHONG CAN TIM LA: "
                    << endl;
                    manager.printRoom(location);
                }
                break;
            }
            case 7 : {
                manager.checkIn();
                break;
            }
            case 8 : {
                manager.checkOut();
                break;
            }
            default : {
                flag = false;
                break;
            }
        }
    } while (flag);
    manager.saveRoomData(ROOMSSAVE);
    manager.saveCustomersData(CUSTOMERSSAVE);
}
