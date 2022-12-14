#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

class Customer
{
private:
    string name;
    string address;
    string phone;
    string from_date;
    string to_date;
    long double advance_payment;
    int booking_id;
public:
    Customer();
    Customer(string,string,string,string,string,long double,int);
    ~Customer();
    void setName(string);
    void setAddress(string);
    void setPhone(string);
    void setFromDate(string);
    void setToDate(string);
    void setAdvancePayment(long double);
    void setBookingId(int);

    string getName() const;
    string getAddress() const;
    string getPhone() const;
    string getFromDate() const;
    string getToDate() const;
    long double getAdvancePayment() const;
    int getBookingId() const;
};
