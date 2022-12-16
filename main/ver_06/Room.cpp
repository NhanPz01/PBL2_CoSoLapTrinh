#include <string>
#include "Room.h"
#include <iostream>
using namespace std;
Room::Room(){

}

ostream& operator<<(ostream& o, const Room& r){
	o << "Room number: ";
	o <<  r.getRoomNumber() << endl;
	o << "Room status: ";
	o <<  r.getStatus() << endl;
	o << "Room type: ";
	o <<  r.getType() << endl;
	o << "Room rent: ";
	o <<  r.getRent() << endl;
	return o;
}

istream& operator>>(istream& i, Room& r){
	int n; bool s,t; long double p;
	cout << "Room number: ";
	i >> n;
	r.setRoomNumber(n);
	cout << "Room status: ";
	i >> s;
	r.setStatus(s);
	cout << "Room type: ";
	i >> t;
	r.setType(t);
	cout << "Room rent: ";
	i >> p;
	r.setRent(p);
	return i;
}

int Room::getRoomNumber() const{
	return this->roomNumber;
}

bool Room::getStatus() const{
	return this->status;
}

bool Room::getType() const{
	return this->type;
}

long double Room::getRent() const{
	return this->rent;
}

void Room::setRoomNumber(int n){
	this->roomNumber = n;
}

void Room::setStatus(bool s){
	this->status = s;
}
void Room::setType(bool t){
	this->type = t;
}
void Room::setRent(long double p){
	this->rent = p;
}

Room::~Room(){
	delete this;
}




