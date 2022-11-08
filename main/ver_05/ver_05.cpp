#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "HotelMgnt.h"

#define max 100
using namespace std;

// Global Declarations
class Room rooms[max];
int count = 0; // number of room.

// managing rooms (adding and searching available rooms)
void manageRooms(Room rooms[], int numberOfRoom)
{
	class Room room;
	int opt, roomNumber, i, flag = 0;
	do
	{
		system("cls");
		cout << "\n### Manage Rooms ###";
		cout << "\n1. Add Room";
		cout << "\n2. Search Room";
		cout << "\n3. Back to Main Menu";
		cout << "\n\nEnter Option: ";
		cin >> opt;

		// switch statement
		switch (opt)
		{
		case 1:
			cout << "\nEnter Room Number: ";
			cin >> roomNumber;
			i = 0;
			for (i = 0; i < numberOfRoom; i++)
			{
				if (rooms[i].getRoomNumber() == roomNumber)
				{
					flag = 1;
				}
			}
			if (flag == 1)
			{
				cout << "\nRoom Number is Present.\nPlease enter unique Number";
				flag = 0;
				getch();
			}
			else
			{
				rooms[numberOfRoom] = room.addRoom(roomNumber);
				numberOfRoom++;
			}
			break;
		case 2:
			cout << "\nEnter room number: ";
			cin >> roomNumber;
			room.searchRoom(count, roomNumber, rooms);
			break;
		case 3:
			// do nothing
			break;
		default:
			cout << "\nPlease Enter correct option";
			break;
		}
	} while (opt != 3);
}

void getRoomsData(const string ROOMS, Room rooms[], int numberOfRoom)
{
	ifstream roomsFile;
	roomsFile.open(ROOMS);
	if (!roomsFile.is_open())
	{
		cout << "Unable to get the rooms information" << endl;
	}
	else
	{
		roomsFile >> numberOfRoom;
		for (int i = 0; i < numberOfRoom; i++) {
			class Room room;
			string ac, type, stype;
			int roomNumber, rent, status;
			roomsFile >> roomNumber;
			room.setRoomNumber(roomNumber);
			roomsFile >> ac;
			room.setAc(ac);
			roomsFile >> type;
			room.setType(type);
			roomsFile >> stype;
			room.setStype(stype);
			roomsFile >> rent;
			room.setRent(rent);
			roomsFile >> status;
			room.setStatus(status);
			rooms[i] = room;
		}
	}
	roomsFile.close();
}

void saveRoomsData(const string ROOMS, Room rooms[], int numberOfRoom)
{
	ofstream roomsFile;
	roomsFile.open(ROOMS);
	if (!roomsFile.is_open()) {
		cout << "Unable to save the rooms information" << endl;
	} else {
		roomsFile << numberOfRoom << endl;
		for (int i = 0; i < numberOfRoom; i++) {
			roomsFile << rooms[i].getRoomNumber() << endl;
			roomsFile << rooms[i].getAc() << endl;
			roomsFile << rooms[i].getType() << endl;
			roomsFile << rooms[i].getStype() << endl;
			roomsFile << rooms[i].getRent() << endl;
			roomsFile << rooms[i].getStatus() << endl;
		}
	}
	roomsFile.close();
}

void getGuestsData(const string GUEST) {

}

using namespace std;
int main()
{
	string const ROOMS = "rooms.txt";
	string const ROOMSSAVE = "rooms.txt";
	getRoomsData(ROOMS, rooms, count);
	class HotelMgnt hotelManagement;
	int i, j, opt, rno;
	string pname;

	system("cls");

	do
	{
		system("cls");
		cout << "######## Hotel Management #########\n";
		cout << "\n1. Manage Rooms";
		cout << "\n2. Check-In Room";
		cout << "\n3. Available Rooms";
		cout << "\n4. Search Customer";
		cout << "\n5. Check-Out Room";
		cout << "\n6. Guest Summary Report";
		cout << "\n7. Exit";
		cout << "\n\nEnter Option: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			manageRooms(rooms, count);
			break;
		case 2:
			if (count == 0)
			{
				cout << "\nRooms data is not available.\nPlease add the rooms first.";
				getch();
			}
			else
				hotelManagement.checkIn(rooms, count);
			break;
		case 3:
			if (count == 0)
			{
				cout << "\nRooms data is not available.\nPlease add the rooms first.";
				getch();
			}
			else
				hotelManagement.getAvailRoom(rooms, count);
			break;
		case 4:
			if (count == 0)
			{
				cout << "\nRooms are not available.\nPlease add the rooms first.";
				getch();
			}
			else
			{
				cout << "Enter Customer Name: ";
				cin.ignore();
				getline(cin, pname);
				hotelManagement.searchCustomer(rooms, count, pname);
			}
			break;
		case 5:
			if (count == 0)
			{
				cout << "\nRooms are not available.\nPlease add the rooms first.";
				getch();
			}
			else
			{
				cout << "Enter Room Number : ";
				cin >> rno;
				hotelManagement.checkOut(rooms, count, rno);
			}
			break;
		case 6:
			hotelManagement.guestSummaryReport(rooms, count);
			break;
		case 7:
			saveRoomsData(ROOMSSAVE, rooms, count);
			cout << "\nTHANK YOU! FOR USING SOFTWARE";
			break;
		default:
			cout << "\nPlease Enter correct option";
			break;
		}
	} while (opt != 7);

	getch();
}
