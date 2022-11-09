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
		if (rooms[i].getStatus() == 1)
		{
			cout << "\n Customer First Name : " << rooms[i].getCustomer().getName();
			cout << "\n Room Number : " << rooms[i].getRoomNumber();
			cout << "\n Address (only city) : " << rooms[i].getCustomer().getAddress();
			cout << "\n Phone : " << rooms[i].getCustomer().getPhone();
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
        string name, address, phone, from_date, to_date;
        int booking_id;
        float payment_advance;
		cout << "\nEnter booking id: ";
		cin >> booking_id;
		cout << "\nBooking id: " << rooms[i].getCustomer().getBookingId() << "\n\n";
        rooms[i].getCustomer().setBookingId(booking_id);
		cout << "\nEnter Customer Name (Full Name): ";
		// cin.ignore();
		getline(cin, name);
		cout << "\nBooking id: " << rooms[i].getCustomer().getName() << "\n\n";
        rooms[i].getCustomer().setName(name);
		cout << "\nEnter Address (only city): ";
		getline(cin, address);
        rooms[i].getCustomer().setAddress(address);
		cout << "\nEnter Phone: ";
		cin >> phone;
        rooms[i].getCustomer().setPhone(phone);
		cout << "\nEnter From Date: ";
		cin >> from_date;
        rooms[i].getCustomer().setFromDate(from_date);

		cout << "\nEnter to  Date: ";
		cin >> to_date;
        rooms[i].getCustomer().setToDate(to_date);

		cout << "\nEnter Advance Payment: ";
		cin >> payment_advance;
        rooms[i].getCustomer().setPaymentAdvance(payment_advance);

		rooms[i].setStatus(1);

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
		if ((rooms[i].getStatus() == 1) && (rooms[i].getCustomer().getName() == pname))
		{
			cout << "\nCustomer Name: " << rooms[i].getCustomer().getName();
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
