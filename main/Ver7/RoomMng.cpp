#include "RoomMng.h"
#include <vector>

void drawaline()
{
    for (int i = 0; i < 100; i++)
    {
        cout << "=";
    }
}

void RoomMng::add()
{
    int size = this->manage.size();
    Room *a = new Room;
    this->manage.push_back(a);
    cin >> *(this->manage[size]);
}
void RoomMng::add(Room *n)
{
    this->manage.push_back(n);
}
void RoomMng::remove(int index)
{

    (this->manage).erase((this->manage).begin() + index);
}
void RoomMng::printAll()
{
    drawaline();
    cout << endl
         << "Tat Ca Cac Phong: ";
    for (int i = 0; i < this->manage.size(); i++)
        cout << endl
             << *(this->manage[i]);
    drawaline();
}
void RoomMng::printAvailable()
{
    drawaline();
    cout << endl
         << "Tat Ca Cac Phong Hien Dang Trong: ";
    for (int i = 0; i < this->manage.size(); i++)
        if ((*this->manage[i]).getStatus() == 0)
            cout << endl
                 << "Phong:" << (*this->manage[i]).getRoomNumber();
    cout << endl;
    drawaline();
}
void RoomMng::updateRoom(int index)
{
    int s;
    cout << "\t   Cap Nhat:" << endl;
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
        cout << "\tNhap So Phong Muon Doi: \n";
        cin >> i;
        (*this->manage[index]).setRoomNumber(i);
        break;
    }

    case 2:
    {
        bool i;
        cout << "\tNhap 0: Phong 2 Nguoi";
        cout << "\n\tNhap 1: Phong Gia Dinh\n";
        cin >> i;
        (*this->manage[index]).setType(i);
        break;
    }
    case 3:
    {
        double i;
        cout << "\tNhap Tien Thue Moi: \n";
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