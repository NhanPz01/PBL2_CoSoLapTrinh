#include "Room.h"
Room::Room(){
}
Room::Room(bool status, int roomNumber, double rent, bool type)
	: status(status), roomNumber(roomNumber), rent(rent), type(type) {
}
Room::~Room(){
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
double Room::getRent() const{
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
void Room::setRent(double p){
	this->rent = p;
}

ostream& operator<<(ostream &o, const Room& r){
	o << "Room number: " << r.getRoomNumber() << "\nRoom status: " << r.getStatus() << "\nRoom type: " <<  r.getType() << "\nRoom rent: " <<  r.getRent() << endl;
	return o;
}

istream& operator>>(istream &i, Room& r){
	int n; bool s,t; double p;
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






