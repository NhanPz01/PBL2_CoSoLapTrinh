#include "Customer.h"

Customer::Customer(){
}

Customer::Customer(string name, string address, string phone, string from_date, string to_date, long double advance_payment, int booking_id)
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
void Customer::setAdvancePayment(long double advance_payment){
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
long double Customer::getAdvancePayment() const{
    return this->advance_payment;
}
int Customer::getBookingId() const{
    return this->booking_id;
}
