#include "Customer.h"
#include "Room.h"
#include <vector>
template <typename T>
class Management{
    Room rooms;
    Customer customers;
    public:
        Management();
        Management(Room&, Customer&);
        ~Management();

        void setRoom(Room&,int);
        void setCustomer(Customer&,int);

        Room getRoom(int) const;
        Customer getCustomer(int) const;
        
        void print();
};