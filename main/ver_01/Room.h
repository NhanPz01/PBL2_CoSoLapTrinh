#include "Customer.h"
class Room {
	protected:
		char type;
		char sizeType;
		char ac;
		int roomNumber;
		int rent;
		int status;
		class Customer cust;
    public:
		void setType(char);
		void setSizeType(char);
        void setAc(char);
		void setRoomNumber(int);
		void setRent(int);
        void setStatus(int);
		char getType() const;
		char getSizeType() const;
		char getAc() const;
        int getRoomNumber() const;
		int getRent() const;
        int getStatus() const;
		class Room addRoom(int);
		void searchRoom(int, const Room&);
		void deleteRoom(int, const Room&);
		void displayRoom(Room);
};
