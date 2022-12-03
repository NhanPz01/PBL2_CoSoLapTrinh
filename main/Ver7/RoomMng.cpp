#include "RoomMng.h"
#include <vector>

void RoomMng::add() {
    int size = this->manage.size();
    Room* a = new Room;
    this->manage.push_back(a);
    cin >> *(this->manage[size]);
}
void RoomMng::add(Room *n){
    this->manage.push_back(n);
}
void RoomMng::remove(int index) {
    
    (this->manage).erase((this->manage).begin()+index);
}
void RoomMng::printAll(){
    cout << endl << "All Room: " << endl;
    for( int i = 0; i < this->manage.size(); i++ ) 
        cout << endl << *(this->manage[i]);
}
void RoomMng::printAvailable(){
    cout << endl << "Available Room: ";
    for ( int i = 0; i < this->manage.size(); i++ )
        if ((*this->manage[i]).getStatus() == 1)
            cout << endl << (*this->manage[i]).getRoomNumber();
}
void RoomMng::updateRoom(int index){
    cout << endl << "Update Room: " << endl;
    cin >> *this->manage[index];
}
