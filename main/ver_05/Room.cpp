#include <iostream>
#include <conio.h>
#include "Room.h"

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
	room.roomNumber = roomNumber;
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

void Room::searchRoom(int roomNumber, int numberOfRoom, Room rooms[])
{
	int i, found = 0;
	for (i = 0; i < numberOfRoom; i++)
	{
		if (rooms[i].roomNumber == roomNumber)
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
