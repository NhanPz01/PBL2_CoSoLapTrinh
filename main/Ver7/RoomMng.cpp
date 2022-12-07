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
void RoomMng::updateRoom(int index)
{
    int s;
    cout << "\t   CapNhat:" << endl;
    cout << "\t1. So Phong" << endl;
    cout << "\t2. Loai Phong" << endl;
    cout << "\t3. Tien Thue Phong" << endl;
    cout << "\t4. Khach Hang" << endl;
    cin >> s;
    switch (s)
    {
    case 1: 
    {   
        int i;
        cout << "\tNhap So Phong Muon Doi: ";
        cin >> i;
        (*this->manage[index]).setRoomNumber(i);
        break;
    }

    case 2: 
    {   
        bool i;
        cout << "\t\tNhap 0: Phong 2 Nguoi";
        cout << "\n\t\tNhap 1: Phong Gia Dinh";
        cin >> i;
        (*this->manage[index]).setType(i);
        break;
    }
    case 3: 
    {   
        double i;
        cout << "Nhap Tien Thue Moi: ";
        cin >> i;
        (*this->manage[index]).setRent(i);
        break;
    }
    case 4: 
    {
        (*this->manage[index]).getCustomer().update();
        break;
    }
}
}
// void RoomMng::addCust(int index){
//     (*this->manage[index]).getCustomer().update();
// }
// void RoomMng::addCust(int index, Customer* customer){
//     (*this->manage[index]).getCustomer() = customer;
// }