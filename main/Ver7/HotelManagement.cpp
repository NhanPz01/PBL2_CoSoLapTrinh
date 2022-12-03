#include "HotelManagement.h"
#include <iostream>
#include <vector>
using namespace std;

Management::Management(){
}

Management::~Management(){}

Management::Management(Room r, Customer c){
    this->room(r);
    this->customer(c);
}

void Management::print(){
    cout << this->room << this->customer;
}
