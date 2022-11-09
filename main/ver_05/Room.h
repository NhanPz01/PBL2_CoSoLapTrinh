#include <string>
#include "Customer.h"

class Room
{
private:
	string type;
	string stype;
	string ac;
	int roomNumber;
	int rent;
	int status;
	class Customer cust;
public:
    void setType(string);
    void setStype(string);
    void setAc(string);
    void setRoomNumber(int);
    void setRent(int);
    void setStatus(int);
    void setCustomer(Customer);
    string getType() const;
    string getStype() const;
    string getAc() const;
    int getRoomNumber() const;
    int getRent() const;
    int getStatus() const;
    Customer getCustomer() const;
	Room addRoom(int);
	void searchRoom(int, int&, Room*);
	void displayRoom(Room);
    friend ostream& operator<<(ostream& o, const Customer& cust)
};
