#include "HotelManagement.h"
#include <iostream>
#include <vector>
using namespace std;



Management::Management(){

}

Management::~Management(){}

Management::Management(Room *r, Customer *c){
    rooms.push_back(r);
    customers.push_back(c);
}

void Management::print(){
    for(int i = 0; i < this->rooms.size(); i++){
        cout << *this->rooms[i] << *this->customers[i];
}
}