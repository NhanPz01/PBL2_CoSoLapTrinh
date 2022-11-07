#include <iostream>
#include <conio.h>
#include "Customer.h"

void Customer::setName(string name)
{
    this->name = name;
}

void Customer::setAddress(string address)
{
    this->address = address;
}

void Customer::setPhone(string phone)
{
    this->phone = phone;
}
void Customer::setFromDate(string from_date)
{
    this->from_date = from_date;
}
void Customer::setToDate(string to_date)
{
    this->to_date = to_date;
}
void Customer::setPaymentAdvance(float payment_advance)
{
    this->payment_advance = payment_advance;
}
void Customer::setBookingId(int booking_id)
{
    this->booking_id = booking_id;
}
string Customer::getName() const
{
    return this->name;
}
string Customer::getAddress() const
{
    return this->address;
}
string Customer::getPhone() const
{
    return this->phone;
}
string Customer::getFromDate() const
{
    return this->from_date;
}
string Customer::getToDate() const
{
    return this->to_date;
}
float Customer::getPaymentAdvance() const
{
    return this->payment_advance;
}
int Customer::getBookingId() const
{
    return this->booking_id;
}
