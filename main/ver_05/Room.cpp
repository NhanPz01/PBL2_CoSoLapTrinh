#include <iostream>
#include <conio.h>
#include "Room.h"

// ostream& operator<<(ostream& o, const Customer& cust){

// }

void Room::setType(string type)
{
    this->type = type;
}

void Room::setStype(string stype)
{
    this->stype = stype;
}

void Room::setAc(string ac)
{
    this->ac = ac;
}

void Room::setRoomNumber(int roomNumber)
{
    this->roomNumber = roomNumber;
}

void Room::setRent(int rent)
{
    this->rent = rent;
}

void Room::setStatus(int status)
{
    this->status = status;
}

void Room::setCustomer(Customer& cust)
{
    this->cust = cust;
}

string Room::getType() const
{
    return this->type;
}

string Room::getStype() const
{
    return this->stype;
}

string Room::getAc() const
{
    return this->ac;
}

int Room::getRoomNumber() const
{
    return this->roomNumber;
}

int Room::getRent() const
{
    return this->rent;
}

int Room::getStatus() const
{
    return this->status;
}

Customer Room::getCustomer() const
{
    return this->cust;
}

Room Room::addRoom(int roomNumber)
{
	class Room room;
	string type, stype, ac;
	int rent;

	room.setRoomNumber(roomNumber);

	cout << "\nType AC/Non-AC (A/N) : ";
	cin >> ac;
	room.setAc(ac);

	cout << "\nType Comfort (S/N) : ";
	cin >> type;
	room.setType(type);

	cout << "\nType Size (B/S) : ";
	cin >> stype;
	room.setStype(stype);

	cout << "\nDaily Rent : ";
	cin >> rent;
	room.setRent(rent);

	room.setStatus(0);

	cout << "\n Room Added Successfully!";
	getch();
	return room;
}

void Room::searchRoom(int roomNumber, int& numberOfRoom, Room rooms[])
{
	int i, found = 0;
	for (i = 0; i < numberOfRoom; i++)
	{
		if (rooms[i].getRoomNumber() == roomNumber)
		{
			found = 1;
			break;
		}
	}
	if (found == 1)
	{
		cout << "Room Details\n";
		if (rooms[i].getStatus() == 1)
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
	cout << "\nRoom Number: \t" << tempRoom.getRoomNumber();
	cout << "\nType AC/Non-AC (A/N) " << tempRoom.getAc();
	cout << "\nType Comfort (S/N) " << tempRoom.getType();
	cout << "\nType Size (B/S) " << tempRoom.getStype();
	cout << "\nRent: " << tempRoom.getRent();
}
