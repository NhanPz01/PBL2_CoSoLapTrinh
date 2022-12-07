#include "Customer.h"
#include <string>
#include <iostream>
using namespace std;
class Room
{
private:
    bool status;
    int roomNumber;
    double rent;
    bool type;
    Customer *customer;

public:
    Room();
    Room(bool, int, double, bool);
    ~Room();
    void setType(bool);
    void setRoomNumber(int);
    void setRent(double);
    void setStatus(bool);
    void setCustomer(Customer*);

    bool getType() const;
    int getRoomNumber() const;
    double getRent() const;
    bool getStatus() const;
    Customer getCustomer() ;
    void removeCustomer();
    
    void addCust(Customer*);
    void removeCust();
    friend ostream &operator<<(ostream &, const Room &);
    friend istream &operator>>(istream &, Room &);
    Room operator=(const Room&);
};