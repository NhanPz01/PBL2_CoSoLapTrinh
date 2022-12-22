#include "Room.h"
Room TestRoom(1, 1, 1, 1);
Date NGAY_TRONG(0, 0, 0);
Customer PHONG_TRONG("Chua co", "Chua co", "Chua co", NGAY_TRONG, NGAY_TRONG, 0, 0);
void Room::setEmptyRoom()
{
	this->customer = &PHONG_TRONG;
}
Room::Room()
{
	this->customer = &PHONG_TRONG;
	this->status = 0;
}

Room::Room(bool status, int roomNumber, long double rent, bool type)
	: status(status), roomNumber(roomNumber), rent(rent), type(type)
{
	this->customer = &PHONG_TRONG;
}

Room::Room(bool status, int roomNumber, long double rent, bool type, Customer *c) : status(status), roomNumber(roomNumber), rent(rent), type(type)
{
	this->customer = c;
}

Room::~Room()
{
}

int Room::getRoomNumber() const
{
	return this->roomNumber;
}
bool Room::getStatus() const
{
	return this->status;
}
bool Room::getType() const
{
	return this->type;
}
long double Room::getRent() const
{
	return this->rent;
}

Customer *Room::getCustomer()
{
	return this->customer;
}

void Room::setRoomNumber(int n)
{
	this->roomNumber = n;
}
void Room::setStatus(bool s)
{
	this->status = s;
}
void Room::setType(bool t)
{
	this->type = t;
}
void Room::setRent(long double p)
{
	this->rent = p;
}

void Room::setCustomer(Customer *customer)
{	
	this->customer = customer;
}

ostream &operator<<(ostream &o, const Room &r)
{
	o << "So Phong: " << r.getRoomNumber()
	  << "\nTinh Trang: ";
	if (r.getStatus() == false)
		cout << "Phong Trong";
	else
		cout << "Phong Da Co Nguoi";
	o << "\nLoai Phong: ";
	if (r.getType() == false)
		cout << "Phong don/doi";
	else
		cout << "Phong gia dinh";
	o << "\nTien Phong: " << r.getRent();
	if (r.getStatus() == true)
	{
		o << "\nKhach Dat Phong: " << (*r.customer);
	}
	cout << endl;
	return o;
}

istream &operator>>(istream &i, Room &r)
{	
	system("cls");
	int n;
	bool s, t;
	long double p;
	Customer *tempCustomer = new Customer;
	cout << "Vui Long Nhap So Phong: ";
	i >> n;
	r.setRoomNumber(n);
	cout << "Tinh Trang Phong (Phong Trong = 0, Phong Da Co Nguoi = 1): ";
	i >> s;
	r.setStatus(s);
	cout << "Loai Phong (Phong don/doi = 0, Phong gia dinh = 1): ";
	i >> t;
	r.setType(t);
	cout << "Tien Phong: ";
	i >> p;
	r.setRent(p);
	if (s == 1)
	{
		i >> *tempCustomer;
		r.setCustomer(tempCustomer);
	}
	else r.setCustomer(&PHONG_TRONG);
	r.statusCheck();
	return i;
	system("pause");
	system("cls");
}

Room Room::operator=(const Room &r)
{
	this->status = r.status;
	this->roomNumber = r.roomNumber;
	this->rent = r.rent;
	this->type = r.type;
	this->customer = r.customer;
	return *this;
}

void Room::addCust(Customer *cust)
{
	this->customer = cust;
	this->status = 1;
}

void Room::removeCust()
{
	this->customer = &PHONG_TRONG;
	this->status = 0;
}

void Room::statusCheck()
{
	if ((*this->customer).getName() == "Chua co")
		this->status = 0;
	else if ((*this->customer).getName() == "")
		this->status = 0;
	else
		this->status = 1;
}
