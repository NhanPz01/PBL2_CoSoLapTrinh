#include "Customer.h"
#include <string>
Customer::Customer(){
}

Customer::Customer(string name, string address, string phone, string from_date, string to_date, double advance_payment, int booking_id)
    : name(name), address(address), phone(phone), from_date(from_date), to_date(to_date), advance_payment(advance_payment), booking_id(booking_id) {
}

Customer::~Customer(){
}

void Customer::setName(string name){
    this->name = name;
}
void Customer::setAddress(string address){
    this->address = address;
}
void Customer::setPhone(string phone){
    this->phone = phone;
}
void Customer::setFromDate(string from_date){
    this->from_date = from_date;
}
void Customer::setToDate(string to_date){
    this->to_date = to_date;
}
void Customer::setAdvancePayment(double advance_payment){
    this->advance_payment = advance_payment;
}
void Customer::setBookingId(int booking_id){
    this->booking_id = booking_id;
}

string Customer::getName() const{
    return this->name;
}
string Customer::getAddress() const{
    return this->address;
}
string Customer::getPhone() const{
    return this->phone;
}
string Customer::getFromDate() const{
    return this->from_date;
}
string Customer::getToDate() const{
    return this->to_date;
}
double Customer::getAdvancePayment() const{
    return this->advance_payment;
}
int Customer::getBookingId() const{
    return this->booking_id;
}

ostream& operator<<(ostream& o, const Customer& c){
    o << "\nTen: " << c.getName() << "\nDiaChi: " << c.getAddress() << "\nNgayCheckIn: " << c.getFromDate() << "\nNgayCheckOut: " << c.getToDate() << "\nTienCoc: " << c.getAdvancePayment() << "\nID: " << c.getBookingId() << endl;
    return o;
}
istream& operator>>(istream& i, Customer& c){
    string n,a,p,fd,td; double ap; int id;
	cout << "\nTen: ";
    getline(i, n);
    c.setName(n);
    cout << "\nDiaChi: ";
    getline(i, a);
    c.setAddress(a);
    cout << "\nSDT: ";
    getline(i, p);
    c.setPhone(p);
    cout << "\nNgayCheckIn: ";
    getline(i, fd);
    c.setFromDate(fd);
    cout << "\nNgayCheckOut: ";
    getline(i, td);
    c.setToDate(td);
    cout << "\nTienCoc: ";
    i >> ap;
    c.setAdvancePayment(ap);
    cout << "\nID: ";
    i >> id;
    c.setBookingId(id);
    return i;
}