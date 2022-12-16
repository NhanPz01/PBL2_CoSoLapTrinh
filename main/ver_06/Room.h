#include <string>
#include <iostream>
using namespace std;
class Room
{
private:
    bool status;
    int roomNumber;
    long double rent;
    bool type;
    // Customer customer;

public:
    Room();
    Room(bool, int, long double, bool);
    ~Room();
    void setType(bool);
    void setRoomNumber(int);
    void setRent(long double);
    void setStatus(bool);
    // void setCustomer(Customer &);

    bool getType() const;
    int getRoomNumber() const;
    long double getRent() const;
    bool getStatus() const;
    // Customer getCustomer() const;

    friend ostream& operator<<(ostream &, const Room &);
    friend istream& operator>>(istream &, Room &);
};
