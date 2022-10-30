#include "Room.h"
class HotelMgnt : protected Room {
	public:
		void checkIn(Room&);
		void getAvailRoom(const Room&);
		void searchCustomer(string *);
		void checkOut(int);
		void guestSummaryReport(const Room&);
};
