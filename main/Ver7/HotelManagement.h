#include "Customer.h"
#include "Room.h"
#include <vector>
class Management{
    vector<Room*> rooms;
    vector<Customer*> customers;
    public:
        Management();
        Management(Room*, Customer*);
        ~Management();

        void setRoom(Room&,int);
        void setCustomer(Customer&,int);

        Room getRoom(int) const;
        Customer getCustomer(int) const;
        
        void print();
};