#include "Room.h"

class HotelMgnt : public Room
{
public:
	void guestSummaryReport(Room*, int);
    void checkIn(Room*, int);
	void getAvailRoom(Room*, int);
	void searchCustomer(Room*, int, string);
	void checkOut(Room*, int, int);
	friend void manageRooms(Room*, int);
	friend void getRoomsData(const string, Room*, int);
	friend void saveRoomsData(const string, Room*, int);
};
