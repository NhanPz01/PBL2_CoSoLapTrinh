#include "Date.h"

bool Date::isLeapYear(){
    if(this->year % 400 == 0||(this->year % 4 == 0&&this->year % 100 != 0))
        return true;
    else return false;
}

int Date::dayChange(){
    int d = this->getDay() , m = this->getMonth() , y = this->getYear();
    m = (m + 9) % 12;
    y = y - m/10;
    return 365*y + y/4 - y/100 + y/400 + (m*306 + 5)/10 + ( d - 1 );
}

bool Date::checkNgay(){
    if (this->month <1 || this->month >12)
        return false;
    if (day < 1 || day >31)
        return false;
    if (this->month == 2 ){
        if (year % 4 == 0)
            return (day <= 29);
        else
            return (day <= 28);
    }
    if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
        return (day <= 30);
    return true;
}

int Date::toDate(Date& date){
    return date.dayChange() - this->dayChange(); 
}

Date::Date(){
    this->year = 0;
    this->month = 0;
    this->day = 0;
}

Date::Date(int day, int month, int year): day(day), month(month), year(year){
}

Date::Date(const Date& date){
    this->day = date.getDay();
    this->month = date.getMonth();
    this->year = date.getYear();
}

Date::~Date(){
}

int Date::getDay() const {
    return this->day;
}

void Date::setDay(int day){
    this-> day = day;
}

int Date::getMonth() const {
    return this->month;
}

void Date::setMonth(int month){
    this-> month = month;
}

int Date::getYear() const {
    return this->year;
}

void Date::setYear(int year){
    this-> year = year;
}

istream& operator>>(istream& i, Date& date){
    bool w = false;
    while (w == false) {
    int year, month, day;
    cout << endl << " Nhap ngay:  ";
    i>> day;
    date.setDay(day);
    cout << " Nhap thang: ";
    i>> month;
    date.setMonth(month);
    cout << " Nhap nam: ";
    i>> year;
    date.setYear(year);
    w = date.checkNgay();
    if (date.checkNgay() == false)
        cout << endl << "Nhap sai, vui long nhap lai.";
    }
    return i;
}

ostream& operator<<(ostream& o, const Date& date){
    o << date.day << "/" << date.month << "/" << date.year;
    return o;
}

Date Date::operator=(const Date& date){
    this->day = date.getDay();
    this->month = date.getMonth();
    this->year = date.getYear();
}
