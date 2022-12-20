#include <iostream>
using namespace std;
class Date
{
private:
    int month;
    int day;
    int year;
public:
    Date();
    Date(int,int, int);
    Date(const Date&);
    ~Date();
    
    int getDay() const;
    void setDay(int);
    int getMonth() const;
    void setMonth(int);
    int getYear() const;
    void setYear(int);
    int dayChange();
    bool isLeapYear();
    bool checkNgay();
    int toDate(Date&);
    
    friend istream& operator>>(istream&, Date& );
    friend ostream& operator<<(ostream&, const Date&);
    Date operator=(const Date&);
};