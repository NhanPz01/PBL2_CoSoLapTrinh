#include "HotelMgnt.h"
#include "Room.h"
using namespace std;

void HotelMgnt::guestSummaryReport(const Room& rooms) {
	if (count == 0) {
		cout << "\n No Guest in Hotel !!";
	}
	for (int i = 0; i < count; i++) {
		if (rooms[i].getStatus() == 1) {
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
void HotelMgnt::checkIn(Room& rooms) {
	int i, found = 0, roomNumber;

	class Room room;
	cout << "\nEnter Room number : ";
	cin >> roomNumber;
	for (i = 0; i < count; i++)
	{
		if (rooms[i].setRoomNumber() == roomNumber)
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

		cout << "\nEnter booking id: ";
		cin >> rooms[i].cust.setBookingId();

		cout << "\nEnter Customer Name (First Name): ";
		cin >> rooms[i].cust.setName();

		cout << "\nEnter Address (only city): ";
		cin >> rooms[i].cust.setAddress();

		cout << "\nEnter Phone: ";
		cin >> rooms[i].cust.setPhone();

		cout << "\nEnter From Date: ";
		cin >> rooms[i].cust.setFromDate();

		cout << "\nEnter to  Date: ";
		cin >> rooms[i].cust.setToDate();

		cout << "\nEnter Advance Payment: ";
		cin >> rooms[i].cust.setPaymentAdvance();

		rooms[i].setStatus() = 1;

		cout << "\n Customer Checked-in Successfully..";
		getch();
	}
}

// hotel management shows available rooms
void HotelMgnt::getAvailRoom()
{
	int i, found = 0;
	for (i = 0; i < count; i++)
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
	for (i = 0; i < count; i++)
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
	for (i = 0; i < count; i++)
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
