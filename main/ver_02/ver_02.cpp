#include <iostream>
#include <string>
#include <conio.h>

#define max 100
using namespace std;

// Class Customer
class Customer
{
protected:
	string name;
	string address;
	string phone;
	string from_date;
	string to_date;
	float payment_advance;
	int booking_id;

public:
	Customer();
	~Customer();
	void setName(string);
	void setAddress(string);
	void setPhone(string);
	void setFromDate(string);
	void setToDate(string);
	void setPaymentAdvance(float);
	void setBookingId(int);
	string getName() const;
	string getAddress() const;
	string getPhone() const;
	string getFromDate() const;
	string getToDate() const;
	float getPaymentAdvance() const;
	int getBookingId() const;
};

void Customer::setName(string name) {
	this->name = name;
}

void Customer::setAddress(string address) {
	this->address = address;
}

void Customer::setPhone(string phone) {
	this->phone = phone;
}

void Customer::setFromDate(string from_date) {
	this->from_date = from_date;
}

void Customer::setToDate(string to_date) {
	this->to_date = to_date;
}

void Customer::setPaymentAdvance(float payment_advance) {
	this->payment_advance = payment_advance;
}

void Customer::setBookingId(int booking_id) {
	this->booking_id = booking_id;
}

string Customer::getName() const
{
	return this->name;
}

string Customer::getAddress() const
{
	return this->address;
}

string Customer::getPhone() const
{
	return this->phone;
}

string Customer::getFromDate() const
{
	return this->from_date;
}

string Customer::getToDate() const
{
	return this->to_date;
}

float Customer::getPaymentAdvance() const
{
	return this->payment_advance;
}

int Customer::getBookingId() const
{
	return this->booking_id;
}

class Room
{
public:
	string type;
	string stype;
	string ac;
	int roomNumber;
	int rent;
	int status;

	Room();
	~Room();
	void setType(string);
	void setStype(string);
    void setAc(string);
	void setRoomNumber(int);
    void setRent(int);
	void setStatus(int);
	string getType() const;
    string getStype() const;
	string getAc() const;
    int getRoomNumber() const;
	int getRent() const;
    int getStatus() const;
	class Customer cust;
	class Room addRoom(int);
	void searchRoom(int);
	void displayRoom(Room);
	friend class HotelMgnt;
};

// Global Declarations
class Room rooms[max];
int roomCount = 0;

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

void Room::searchRoom(int roomNumber)
{
	int i, found = 0;
	for (i = 0; i < roomCount; i++)
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

// hotel management class
class HotelMgnt
{
public:
	void checkIn();
	void getAvailRoom();
	void searchCustomer(string *);
	void checkOut(int);
	void guestSummaryReport();
};

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
			cout << "\n Customer First Name : " << rooms[i].cust.getName();
			cout << "\n Room Number : " << rooms[i].getRoomNumber();
			cout << "\n Address (only city) : " << rooms[i].cust.getAddress();
			cout << "\n Phone : " << rooms[i].cust.getPhone();
			cout << "\n---------------------------------------";
		}
	}

	getch();
}

// hotel management reservation of room
void HotelMgnt::checkIn()
{
	int i, found = 0, roomNumber;

	class Room room;
	cout << "\nEnter Room number : ";
	cin >> roomNumber;
	for (i = 0; i < roomCount; i++)
	{
		if (rooms[i].getRoomNumber() == roomNumber)
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
		cin >> rooms[i].cust.getBookingId();

		cout << "\nEnter Customer Name (First Name): ";
		cin >> rooms[i].cust.getName();

		cout << "\nEnter Address (only city): ";
		cin >> rooms[i].cust.getAddress();

		cout << "\nEnter Phone: ";
		cin >> rooms[i].cust.getPhone();

		cout << "\nEnter From Date: ";
		cin >> rooms[i].cust.getFromDate();

		cout << "\nEnter to  Date: ";
		cin >> rooms[i].cust.getToDate();

		cout << "\nEnter Advance Payment: ";
		cin >> rooms[i].cust.getPaymentAdvance();

		rooms[i].getStatus() = 1;

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
void HotelMgnt::searchCustomer(string *pname)
{
	int i, found = 0;
	for (i = 0; i < roomCount; i++)
	{
		if (rooms[i].status == 1 && stricmp(rooms[i].cust.name, pname) == 0)
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
	int i, found = 0, days, roomNumber;
	float billAmount = 0;
	for (i = 0; i < roomCount; i++)
	{
		if (rooms[i].status == 1 && rooms[i].roomNumber == roomNum)
		{
			// roomNumber = rooms[i].roomNumber;
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
	int opt, roomNumber, i, flag = 0;
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
			cin >> roomNumber;
			i = 0;
			for (i = 0; i < roomCount; i++)
			{
				if (rooms[i].roomNumber == roomNumber)
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
				rooms[roomCount] = room.addRoom(roomNumber);
				roomCount++;
			}
			break;
		case 2:
			cout << "\nEnter room number: ";
			cin >> roomNumber;
			room.searchRoom(roomNumber);
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
using namespace std;
int main()
{
	class HotelMgnt hm;
	int i, j, opt, roomNumber;
	string ch;
	string pname[100];

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
				hm.checkIn();
			break;
		case 3:
			if (roomCount == 0)
			{
				cout << "\nRooms data is not available.\nPlease add the rooms first.";
				getch();
			}
			else
				hm.getAvailRoom();
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
				cin >> pname;
				hm.searchCustomer(pname);
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
				cin >> roomNumber;
				hm.checkOut(roomNumber);
			}
			break;
		case 6:
			hm.guestSummaryReport();
			break;
		case 7:
			cout << "\nTHANK YOU! FOR USING SOFTWARE";
			break;
		default:
			cout << "\nPlease Enter correct option";
			break;
		}
	} while (opt != 7);

	getch();
}
