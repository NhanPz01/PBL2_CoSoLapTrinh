#include <iostream>
#include <conio.h>
#include "HotelMgnt.h"
using namespace std;

void HotelMgnt::guestSummaryReport(Room rooms[], int& numberOfRoom)
{

	if (numberOfRoom == 0)
	{
		cout << "\n No Guest in Hotel !!";
	}
	for (int i = 0; i < numberOfRoom; i++)
	{
		class Customer cust = rooms[i].getCustomer();
		if (rooms[i].getStatus() == 1)
		{
			cout << "\n Customer First Name : " << cust.getName();
			cout << "\n Room Number : " << rooms[i].getRoomNumber();
			cout << "\n Address (only city) : " << cust.getAddress();
			cout << "\n Phone : " << cust.getPhone();
			cout << "\n---------------------------------------";
		}
	}

	getch();
}

// hotel management reservation of room
void HotelMgnt::checkIn(Room rooms[], int& numberOfRoom)
{
	int i, found = 0, roomNumber;

	class Room room;
	cout << "\nEnter Room number : ";
	cin >> roomNumber;
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
		if (rooms[i].getStatus() == 1)
		{
			cout << "\nRoom is already Booked";
			getch();
			return;
		}
		class Customer cust = rooms[i].getCustomer();
		string name, address, phone, from_date, to_date;
		int booking_id;
		float payment_advance;
		cout << "\nEnter booking id: ";
		cin >> booking_id;
        cust.setBookingId(booking_id);
		cout << cust.getBookingId() << endl;

		cout << "\nEnter Customer Name (Full Name): ";
		cin.ignore();
		getline(cin, name);
        cust.setName(name);
		cout << cust.getName() << endl;
		cout << "\nEnter Address (only city): ";
		getline(cin, address);
        cust.setAddress(address);
		cout << cust.getAddress() << endl;
		cout << "\nEnter Phone: ";
		cin >> phone;
        cust.setPhone(phone);
		cout << cust.getPhone() << endl;
		cout << "\nEnter From Date: ";
		cin >> from_date;
        cust.setFromDate(from_date);
		cout << cust.getFromDate() << endl;
		cout << "\nEnter to  Date: ";
		cin >> to_date;
        cust.setToDate(to_date);
		cout << cust.getToDate() << endl;
		cout << "\nEnter Advance Payment: ";
		cin >> payment_advance;
        cust.setPaymentAdvance(payment_advance);
		cout << cust.getPaymentAdvance() << endl;
		rooms[i].setStatus(1);
		rooms[i].setCustomer(cust);
		cout << "\n Customer Checked-in Successfully..";
		getch();
	}
}

// hotel management shows available rooms
void HotelMgnt::getAvailRoom(Room rooms[], int& numberOfRoom)
{
	int i, found = 0;
	for (i = 0; i < numberOfRoom; i++)
	{
		if (rooms[i].getStatus() == 0)
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
void HotelMgnt::searchCustomer(Room rooms[], int& numberOfRoom, string pname)
{
	int i, found = 0;
	for (i = 0; i < numberOfRoom; i++)
	{
		class Customer cust = rooms[i].getCustomer();
		if ((rooms[i].getStatus() == 1) && (cust.getName() == pname))
		{
			cout << "\nCustomer Name: " << cust.getName();
			cout << "\nRoom Number: " << rooms[i].getRoomNumber();

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
void HotelMgnt::checkOut(Room rooms[], int& numberOfRoom, int roomNum)
{
	int i, found = 0, days;
	float billAmount = 0;
	for (i = 0; i < numberOfRoom; i++)
	{
		if (rooms[i].getStatus() == 1 && rooms[i].getRoomNumber() == roomNum)
		{
			found = 1;
			break;
		}
	}
	if (found == 1)
	{
		cout << "\nEnter Number of Days:\t";
		cin >> days;
		billAmount = days * rooms[i].getRent();

		cout << "\n\t######## CheckOut Details ########\n";
		cout << "\nCustomer Name : " << rooms[i].getCustomer().getName();
		cout << "\nRoom Number : " << rooms[i].getRoomNumber();
		cout << "\nAddress : " << rooms[i].getCustomer().getAddress();
		cout << "\nPhone : " << rooms[i].getCustomer().getPhone();
		cout << "\nTotal Amount Due : " << billAmount << " /";
		cout << "\nAdvance Paid: " << rooms[i].getCustomer().getPaymentAdvance() << " /";
		cout << "\n*** Total Payable: " << billAmount - rooms[i].getCustomer().getPaymentAdvance() << "/ only";

		rooms[i].setStatus(0);
	}
	getch();
}
