#include "Customer.h"
using namespace std;

Customer::Customer() {}

Customer::~Customer() {}

void Customer::setName(char& name) {
    this->name = name;
}

void Customer::setAddress(char& address) {
    this->address = address;
}

void Customer::setPhone(char& phone) {
    this->phone = phone;
}

void Customer::setFromDate(char& from_date) {
    this->from_date = from_date;
}

void Customer::setToDate(char& to_date) {
    this->to_date = to_date;
}

void Customer::setPaymentAdvance(float payment_advance) {
    this->payment_advance = payment_advance;
}

void Customer::setBookingId(int booking_id) {
    this->booking_id = booking;
}

char Customer::getName() const {
    return this->name;
}

char Customer::getAddress() const {
    return this->address;
}

char Customer::getPhone() const {
    return this->phone;
}

char Customer::getFromDate() const {
    return this->from_date;
}

char Customer::getToDate() const {
    return this->to_date;
}

float Customer::getPaymentAdvance() const {
    return this->payment_advance;
}

int Customer::getBookingId() const {
    return this->booking_id;
}
