#include "Date.h"
#include <iostream>

int main(){
    Date date(8,3,2002), date2(8,4,2003);
    cout << date.toDate(date2);
    Date date3;
    cin >> date3;
    cout << date3;
    // cout << date;
}