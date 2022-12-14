#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

#define max 100
using namespace std;

// Class Customer
class Customer
{
public:
	string name;
	string address;
	string phone;
	string from_date;
	string to_date;
	float payment_advance;
	int booking_id;
};

// Class Room
class Room
{
public:
	string type;
	string stype;
	string ac;
	int roomNumber;
	int rent;
	int status;

	class Customer cust;
	class Room addRoom(int);
	void searchRoom(int);
	void deleteRoom(int);
	void displayRoom(Room);
};

// Class Hotel Management
class HotelMgnt : protected Room
{
public:
	void checkIn();
	void getAvailRoom();
	void searchCustomer(string);
	void checkOut(int);
	void guestSummaryReport();
};

// Global Declarations
class Room rooms[max];
int roomCount = 0; // number of rooms in rooms.

Room Room::addRoom(int rno)
{
	class Room room;
	room.roomNumber = rno;
	cout << "\nType AC/Non-AC (A/N) : ";
	cin >> room.ac;
	cout << "\nType Comfort (S/N) : ";
	cin >> room.type;
	cout << "\nType Size (B/S) : ";
	cin >> room.stype;
	cout << "\nDaily Rent : ";
	cin >> room.rent;
	room.status = 0;

	cout << "\n Room Added Successfully!";
	getch();
	return room;
}

void Room::searchRoom(int rno)
{
	int i, found = 0;
	for (i = 0; i < roomCount; i++)
	{
		if (rooms[i].roomNumber == rno)
		{
			found = 1;
			break;
		}
	}
	if (found == 1)
	{
		cout << "Room Details\n";
		if (rooms[i].status == 1)
		{
			cout << "\nRoom is Reserved";
		}
		else
		{
			cout << "\nRoom is available";
		}
		displayRoom(rooms[i]);
		getch();
	}
	else
	{
		cout << "\nRoom not found";
		getch();
	}
}

void Room::displayRoom(Room tempRoom)
{
	cout << "\nRoom Number: \t" << tempRoom.roomNumber;
	cout << "\nType AC/Non-AC (A/N) " << tempRoom.ac;
	cout << "\nType Comfort (S/N) " << tempRoom.type;
	cout << "\nType Size (B/S) " << tempRoom.stype;
	cout << "\nRent: " << tempRoom.rent;
}

void HotelMgnt::guestSummaryReport()
{

	if (roomCount == 0)
	{
		cout << "\n No Guest in Hotel !!";
	}
	for (int i = 0; i < roomCount; i++)
	{
		if (rooms[i].status == 1)
		{
			cout << "\n Customer First Name : " << rooms[i].cust.name;
			cout << "\n Room Number : " << rooms[i].roomNumber;
			cout << "\n Address (only city) : " << rooms[i].cust.address;
			cout << "\n Phone : " << rooms[i].cust.phone;
			cout << "\n---------------------------------------";
		}
	}

	getch();
}

// hotel management reservation of room
void HotelMgnt::checkIn()
{
	int i, found = 0, rno;

	class Room room;
	cout << "\nEnter Room number : ";
	cin >> rno;
	for (i = 0; i < roomCount; i++)
	{
		if (rooms[i].roomNumber == rno)
		{
			found = 1;
			break;
		}
	}
	if (found == 1)
	{
		if (rooms[i].status == 1)
		{
			cout << "\nRoom is already Booked";
			getch();
			return;
		}

		cout << "\nEnter booking id: ";
		cin >> rooms[i].cust.booking_id;

		cout << "\nEnter Customer Name (Full Name): ";
		cin.ignore();
		getline(cin, rooms[i].cust.name);
		// cin >> rooms[i].cust.name;

		cout << "\nEnter Address (only city): ";
		// cin >> rooms[i].cust.address;
		// cin.ignore();
		getline(cin, rooms[i].cust.address);
		cout << endl
			 << "address: " << rooms[i].cust.address;

		cout << "\nEnter Phone: ";
		cin >> rooms[i].cust.phone;

		cout << "\nEnter From Date: ";
		cin >> rooms[i].cust.from_date;

		cout << "\nEnter to  Date: ";
		cin >> rooms[i].cust.to_date;

		cout << "\nEnter Advance Payment: ";
		cin >> rooms[i].cust.payment_advance;

		rooms[i].status = 1;

		cout << "\n Customer Checked-in Successfully..";
		getch();
	}
}

// hotel management shows available rooms
void HotelMgnt::getAvailRoom()
{
	int i, found = 0;
	for (i = 0; i < roomCount; i++)
	{
		if (rooms[i].status == 0)
		{
			displayRoom(rooms[i]);
			cout << "\n\nPress enter for next room";
			found = 1;
			getch();
		}
	}
	if (found == 0)
	{
		cout << "\nAll rooms are reserved";
		getch();
	}
}

// hotel management shows all persons that have booked room
void HotelMgnt::searchCustomer(string pname)
{
	int i, found = 0;
	for (i = 0; i < roomCount; i++)
	{
		// if (rooms[i].status == 1 && stricmp(*(rooms + i).cust.name, pname) == 0)
		if ((rooms[i].status == 1) && (rooms[i].cust.name == pname))
		{
			cout << "\nCustomer Name: " << rooms[i].cust.name;
			cout << "\nRoom Number: " << rooms[i].roomNumber;

			cout << "\n\nPress enter for next record";
			found = 1;
			getch();
		}
	}
	if (found == 0)
	{
		cout << "\nPerson not found.";
		getch();
	}
}

// hotel managemt generates the bill of the expenses
void HotelMgnt::checkOut(int roomNum)
{
	int i, found = 0, days, rno;
	float billAmount = 0;
	for (i = 0; i < roomCount; i++)
	{
		if (rooms[i].status == 1 && rooms[i].roomNumber == roomNum)
		{
			// rno = rooms[i].roomNumber;
			found = 1;
			// getch();
			break;
		}
	}
	if (found == 1)
	{
		cout << "\nEnter Number of Days:\t";
		cin >> days;
		billAmount = days * rooms[i].rent;

		cout << "\n\t######## CheckOut Details ########\n";
		cout << "\nCustomer Name : " << rooms[i].cust.name;
		cout << "\nRoom Number : " << rooms[i].roomNumber;
		cout << "\nAddress : " << rooms[i].cust.address;
		cout << "\nPhone : " << rooms[i].cust.phone;
		cout << "\nTotal Amount Due : " << billAmount << " /";
		cout << "\nAdvance Paid: " << rooms[i].cust.payment_advance << " /";
		cout << "\n*** Total Payable: " << billAmount - rooms[i].cust.payment_advance << "/ only";

		rooms[i].status = 0;
	}
	getch();
}

// managing rooms (adding and searching available rooms)
void manageRooms()
{
	class Room room;
	int opt, rno, i, flag = 0;
	string ch;
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
			cin >> rno;
			i = 0;
			for (i = 0; i < roomCount; i++)
			{
				if (rooms[i].roomNumber == rno)
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
				rooms[roomCount] = room.addRoom(rno);
				roomCount++;
			}
			break;
		case 2:
			cout << "\nEnter room number: ";
			cin >> rno;
			room.searchRoom(rno);
			break;
		case 3:
			// nothing to do
			break;
		default:
			cout << "\nPlease Enter correct option";
			break;
		}
	} while (opt != 3);
}

void getRoomsData(const string ROOMS)
{
	ifstream roomsFile;
	roomsFile.open(ROOMS);
	if (!roomsFile.is_open())
	{
		cout << "Unable to get the rooms information" << endl;
	}
	else
	{
		roomsFile >> roomCount;
		for (int i = 0; i < roomCount; i++) {
			Room room;
			roomsFile >> room.roomNumber;
			roomsFile >> room.ac;
			roomsFile >> room.type;
			roomsFile >> room.stype;
			roomsFile >> room.rent;
			roomsFile >> room.status;
			rooms[i] = room;
		}
	}
	roomsFile.close();
}

void saveRoomsData(const string ROOMS) {
	ofstream roomsFile;
	roomsFile.open(ROOMS);
	if (!roomsFile.is_open()) {
		cout << "Unable to save the rooms information" << endl;
	} else {
		roomsFile << roomCount << endl;
		for (int i = 0; i < roomCount; i++) {
			roomsFile << rooms[i].roomNumber << endl;
			roomsFile << rooms[i].ac << endl;
			roomsFile << rooms[i].type << endl;
			roomsFile << rooms[i].stype << endl;
			roomsFile << rooms[i].rent << endl;
			roomsFile << rooms[i].status << endl;
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
	getRoomsData(ROOMS);
	class HotelMgnt hotelManagement;
	int i, j, opt, rno;
	string ch;
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
			manageRooms();
			break;
		case 2:
			if (roomCount == 0)
			{
				cout << "\nRooms data is not available.\nPlease add the rooms first.";
				getch();
			}
			else
				hotelManagement.checkIn();
			break;
		case 3:
			if (roomCount == 0)
			{
				cout << "\nRooms data is not available.\nPlease add the rooms first.";
				getch();
			}
			else
				hotelManagement.getAvailRoom();
			break;
		case 4:
			if (roomCount == 0)
			{
				cout << "\nRooms are not available.\nPlease add the rooms first.";
				getch();
			}
			else
			{
				cout << "Enter Customer Name: ";
				// cin >> pname;
				cin.ignore();
				getline(cin, pname);
				hotelManagement.searchCustomer(pname);
			}
			break;
		case 5:
			if (roomCount == 0)
			{
				cout << "\nRooms are not available.\nPlease add the rooms first.";
				getch();
			}
			else
			{
				cout << "Enter Room Number : ";
				cin >> rno;
				hotelManagement.checkOut(rno);
			}
			break;
		case 6:
			hotelManagement.guestSummaryReport();
			break;
		case 7:
			saveRoomsData(ROOMSSAVE);
			cout << "\nTHANK YOU! FOR USING SOFTWARE";
			break;
		default:
			cout << "\nPlease Enter correct option";
			break;
		}
	} while (opt != 7);

	getch();
}
