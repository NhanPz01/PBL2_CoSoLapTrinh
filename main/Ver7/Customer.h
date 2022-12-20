#include <string>
#include <iostream>
#include <conio.h>
#include "Date.h"
using namespace std;

class Customer
{
private:
    string name;
    string address;
    string phone;
    Date from_date;
    Date to_date;
    long double advance_payment;
    int booking_id;
public:
    Customer();
    Customer(string,string,string,Date&,Date&,long double,int);
    Customer(Customer&);
    ~Customer();
    void setName(string);
    void setAddress(string);
    void setPhone(string);
    void setFromDate(Date&);
    void setToDate(Date&);
    void setAdvancePayment(long double);
    void setBookingId(int);

    string getName() const;
    string getAddress() const;
    string getPhone() const;
    Date getFromDate() const;
    Date getToDate() const;
    long double getAdvancePayment() const;
    int getBookingId() const;

    void update();
    void rev();

    friend ostream& operator<<(ostream&, const Customer&);
    friend istream& operator>>(istream&, Customer&);
    Customer operator=(const Customer&);
};
