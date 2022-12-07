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
    double advance_payment;
    int booking_id;
public:
    Customer();
    Customer(string,string,string,string,string,double,int);
    Customer(Customer&);
    ~Customer();
    void setName(string);
    void setAddress(string);
    void setPhone(string);
    void setFromDate(string);
    void setToDate(string);
    void setAdvancePayment(double);
    void setBookingId(int);

    string getName() const;
    string getAddress() const;
    string getPhone() const;
    string getFromDate() const;
    string getToDate() const;
    double getAdvancePayment() const;
    int getBookingId() const;

    void update();

    friend ostream& operator<<(ostream&, const Customer&);
    friend istream& operator>>(istream&, Customer&);
    Customer operator=(const Customer&);
};