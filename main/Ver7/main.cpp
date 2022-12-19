#include <windows.h>
#include <cwchar>
#include "RoomMng.h"
#include <iostream>
using namespace std;

// void SetColor(int backgound_color, int text_color)
// {
//     HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

//     int color_code = backgound_color * 16 + text_color;
//     SetConsoleTextAttribute(hStdout, color_code);
// }

int main(){
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 30;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
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
        // SetConsoleTextAttribute(console_color, 7);
        // SetColor(7, 0);
        cout << "-----------------------KHACH SAN AHIHI----------------------" << endl;
        cout << "(1) Hien thi tat ca cac phong" << endl;
        cout << "(2) Hien thi phong trong" << endl;
        cout << "(3) Them phong" << endl;
        cout << "(4) Sua thong tin" << endl;
        cout << "(5) Xoa phong" << endl;
        cout << "(6) Tim phong" << endl;
        cout << "(7) Checkin" << endl;
        cout << "(8) Checkout" << endl;
        cout << "(9) Thoat" << endl;
        cout << "Lua chon : ";
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
                break;
            }
            case 4 : {
                cout << "Nhap so phong : ";
                int s;
                cin >> s;
                manager.updateRoom(s);
                break;
            }
            case 5 : {
                cout << "Nhap so phong : ";
                int s;
                cin >> s;
                manager.removeAt(s);
                break;
            }
            case 6 : {
                cout << "Nhap so phong : ";
                int s;
                cin >> s;
                int location = manager.interpolationSearch(s);
                if (location != -1)
                {
                    manager.printRoom(location);
                }
                else
                {
                    cout << "Phong khong ton tai !" << endl;
                    while(location == -1)
                    {
                        cout << "Vui long nhap lai : ";
                        cin >> s;
                        location = manager.interpolationSearch(s);
                    }
                    cout << "\nPhong se bi xoa !" << endl;
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
}
