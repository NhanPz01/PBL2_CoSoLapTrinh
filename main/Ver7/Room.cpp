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

Customer Room::getCustomer() {
	return *this->customer;
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

void Room::setCustomer(Customer *customer){
	this->customer = customer;
}

ostream& operator<<(ostream &o, const Room& r){
	o << "Room number: " << r.getRoomNumber()
	  << "\nRoom status: " << r.getStatus()
	  << "\nRoom type: " <<  r.getType()
	  << "\nRoom rent: " <<  r.getRent()
	  << "\nCustomer in room: " << r.customer
	  << endl;
	return o;
}

istream& operator>>(istream &i, Room& r){
	int n; bool s,t; double p;
	Customer tempCustomer;
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
	i >> tempCustomer;
	r.setCustomer(&tempCustomer);
	return i;
}

Room Room::operator=(const Room& r){
	this->status = r.status;
	this->roomNumber = r.roomNumber;
	this->rent = r.rent;
	this->type = r.type;
	this->customer = r.customer;
	return *this;
}