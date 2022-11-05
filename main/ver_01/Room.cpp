#include <iostream>
#include "Room.h"
using namespace std;

Room::Room() {}

Room::~Room() {}

void Room::setType(string type) {
    this->type = type;
}

void Room::setSizeType(string sizeType) {
    this->sizeType = sizeType;
}

void Room::setAc(string ac) {
    this->ac = ac;
}

void Room::setRoomNumber(int roomNumber) {
    this->roomNumber = roomNumber;
}

void Room::setRent(int rent) {
    this->rent = rent;
}

void Room::setStatus(int status) {
    this->status = status;
}

string Room::getType() const {
    return this->type;
}

string Room::getSizeType() const {
    return this->sizeType;
}

string Room::getAc() const {
    return this->ac;
}

int Room::getRoomNumber() const {
    return this->roomNumber;
}

int Room::getRent() const {
    return this->rent;
}

int Room::getStatus() const {
    return this->status;
}

Room Room::addRoom(int roomNumber) {
	class Room room;
	room.setRoomNumber() = roomNumber;
	cout << "\nType AC/Non-AC (A/N) : ";
	cin >> room.setAc();
	cout << "\nType Comfort (S/N) : ";
	cin >> room.setType();
	cout << "\nType Size (B/S) : ";
	cin >> room.setSizeType();
	cout << "\nDaily Rent : ";
	cin >> room.setRent();
	room.setStatus() = 0;

	cout << "\n Room Added Successfully!";
	getch();
	return room;
}

void Room::searchRoom(int roomNumber, const Room& rooms) {
	int i, found = 0;
	for (i = 0; i < count; i++) {
		if (*(rooms + i).getRoomNumber() == roomNumber) {
			found = 1;
			break;
		}
	}
	if (found == 1) {
		cout << "Room Details\n";
		if (*(rooms + i).getStatus() == 1) {
			cout << "\nRoom is Reserved";
		} else {
			cout << "\nRoom is available";
		}
		displayRoom(*(rooms + i));
		getch();
	} else {
		cout << "\nRoom not found";
		getch();
	}
}

void Room::deleteRoom(int roomNumber, const Room& rooms) {
    for (int i = 0; i < count; i++) {
        if (*(rooms + i).getRoomNumber() == roomNumber) {
            delete [] *(rooms + i);
        }
    }
}

void Room::displayRoom(Room tempRoom) {
	cout << "\nRoom Number: \t" << tempRoom.getRoomNumber();
	cout << "\nType AC/Non-AC (A/N) " << tempRoom.getAc();
	cout << "\nType Comfort (S/N) " << tempRoom.getType();
	cout << "\nType Size (B/S) " << tempRoom.getSizeType();
	cout << "\nRent: " << tempRoom.getRent();
}
