#include "Customer.h"
class Room {
	protected:
		string type;
		string sizeType;
		string ac;
		int roomNumber;
		int rent;
		int status;
		class Customer cust;
    public:
		void setType(string);
		void setSizeType(string);
        void setAc(string);
		void setRoomNumber(int);
		void setRent(int);
        void setStatus(int);
		string getType() const;
		string getSizeType() const;
		string getAc() const;
        int getRoomNumber() const;
		int getRent() const;
        int getStatus() const;
		class Room addRoom(int);
		void searchRoom(int, const Room&);
		void deleteRoom(int, const Room&);
		void displayRoom(Room);
};
