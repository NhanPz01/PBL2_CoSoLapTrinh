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
void RoomMng::removeFirst()
{
    remove(0);
}
void RoomMng::removeLast()
{
    remove(this->manage.size() - 1);
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
void RoomMng::printRoom(int index){
    cout << endl
         << "Phong can tim la: " << *(this->manage[index]);
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
int RoomMng::interpolationSearch(int x)
{   
    if ((*this->manage[0]).getRoomNumber() == x) return 0;
    int lo = 0, hi = (this->manage.size());
    while (lo <= hi && x >= (*this->manage[lo]).getRoomNumber() && x <= (*this->manage[hi]).getRoomNumber())
    {
        if (lo == hi)
        {
            if ((*this->manage[lo]).getRoomNumber() == x) return lo;
            return -1;
        }
        int pos = lo + (((double)(hi - lo) /
            ((*this->manage[hi]).getRoomNumber() - (*this->manage[lo]).getRoomNumber())) * (x - (*this->manage[lo]).getRoomNumber()));
        if ((*this->manage[pos]).getRoomNumber() == x)
            return pos;
        if ((*this->manage[pos]).getRoomNumber() < x)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;}