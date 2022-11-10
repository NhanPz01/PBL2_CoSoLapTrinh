#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "HotelMgnt.h"

#define max 100
using namespace std;

// Global Declarations
class Room rooms[max];
int roomCount = 0;	   // number of room.
int customerCount = 0; // number of customers.

// managing rooms (adding and searching available rooms)
void manageRooms(Room rooms[], int &numberOfRoom)
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
			for (int i = 0; i < numberOfRoom; i++)
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
			room.searchRoom(roomNumber, roomCount, rooms);
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

void getRoomsData(const string ROOMS, Room rooms[], int &numberOfRoom)
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
		for (int i = 0; i < numberOfRoom; i++)
		{
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

void saveRoomsData(const string ROOMS, Room rooms[], int &numberOfRoom)
{
	ofstream roomsFile;
	roomsFile.open(ROOMS);
	if (!roomsFile.is_open())
	{
		cout << "Unable to save the rooms information" << endl;
	}
	else
	{
		roomsFile << numberOfRoom << endl;
		for (int i = 0; i < numberOfRoom; i++)
		{
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

void getCustomersData(const string CUSTOMERS, Room rooms[], int &numberOfCustomers, int &numberOfRoom)
{
	ifstream customersFile;
	customersFile.open(CUSTOMERS);
	if (!customersFile.is_open())
	{
		cout << "Unable to get customers data" << endl;
	}
	else
	{
		customersFile >> numberOfCustomers;
		for (int i = 0; i < numberOfCustomers; i++)
		{
			Customer cust;
			string name, address, phone, from_date, to_date;
			int roomNumber, booking_id;
			float payment_advance;
			customersFile >> roomNumber;
			for (int j = 0; j < numberOfRoom; j++)
			{
				if ((j + 1) == roomNumber)
				{
					rooms[j].setStatus(1);
					customersFile >> booking_id;
					cust.setBookingId(booking_id);

					customersFile.ignore();
					getline(customersFile, name);
					cust.setName(name);

					getline(customersFile, address);
					cust.setAddress(address);

					customersFile >> phone;
					cust.setPhone(phone);

					customersFile >> from_date;
					cust.setFromDate(from_date);

					customersFile >> to_date;
					cust.setToDate(to_date);

					customersFile >> payment_advance;
					cust.setPaymentAdvance(payment_advance);

					rooms[j].setCustomer(cust);
				}
			}
		}
	}
	customersFile.close();
}

void saveCustomersData(const string CUSTOMERS, Room rooms[], int &numberOfCustomer, int &numberOfRoom)
{
	ofstream customersFile;
	customersFile.open(CUSTOMERS);
	if (!customersFile.is_open())
	{
		cout << "Unable to save the customers data" << endl;
	}
	else
	{
		customersFile << numberOfCustomer << endl;
		for (int i = 0; i <= numberOfCustomer; i++)
		{
			Customer cust = rooms[i].getCustomer();
			if (rooms[i].getStatus() == 1)
			{
				rooms[i].setStatus(0);
				customersFile << rooms[i].getRoomNumber() << endl;
				customersFile << cust.getBookingId() << endl;
				customersFile << cust.getName() << endl;
				customersFile << cust.getAddress() << endl;
				customersFile << cust.getPhone() << endl;
				customersFile << cust.getFromDate() << endl;
				customersFile << cust.getToDate() << endl;
				customersFile << cust.getPaymentAdvance() << endl;
			}
		}
	}
	customersFile.close();
}

using namespace std;
int main()
{
	string const ROOMS = "rooms.txt";
	string const ROOMSSAVE = "rooms.txt";
	string const CUSTOMERS = "customers.txt";
	string const CUSTOMERSSAVE = "customers.txt";
	getRoomsData(ROOMS, rooms, roomCount);
	getCustomersData(CUSTOMERS, rooms, customerCount, roomCount);
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
			manageRooms(rooms, roomCount);
			break;
		case 2:
			if (roomCount == 0)
			{
				cout << "\nRooms data is not available.\nPlease add the rooms first.";
				getch();
			}
			else
				hotelManagement.checkIn(rooms, roomCount);
			break;
		case 3:
			if (roomCount == 0)
			{
				cout << "\nRooms data is not available.\nPlease add the rooms first.";
				getch();
			}
			else
				hotelManagement.getAvailRoom(rooms, roomCount);
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
				cin.ignore();
				getline(cin, pname);
				hotelManagement.searchCustomer(rooms, roomCount, pname);
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
				hotelManagement.checkOut(rooms, roomCount, customerCount, rno);
			}
			break;
		case 6:
			hotelManagement.guestSummaryReport(rooms, roomCount);
			break;
		case 7:
			saveRoomsData(ROOMSSAVE, rooms, roomCount);
			saveCustomersData(CUSTOMERSSAVE, rooms, customerCount, roomCount);
			cout << "\nTHANK YOU! FOR USING SOFTWARE";
			break;
		default:
			cout << "\nPlease Enter correct option";
			break;
		}
	} while (opt != 7);

	getch();
}
