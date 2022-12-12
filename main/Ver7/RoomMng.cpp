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
void RoomMng::printRoom(int index)
{
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
    if ((*this->manage[0]).getRoomNumber() == x)
        return 0;
    int lo = 0, hi = (this->manage.size());
    while (lo <= hi && x >= (*this->manage[lo]).getRoomNumber() && x <= (*this->manage[hi]).getRoomNumber())
    {
        if (lo == hi)
        {
            if ((*this->manage[lo]).getRoomNumber() == x)
                return lo;
            return -1;
        }
        int pos = lo + (((double)(hi - lo) /
                         ((*this->manage[hi]).getRoomNumber() - (*this->manage[lo]).getRoomNumber())) *
                        (x - (*this->manage[lo]).getRoomNumber()));
        if ((*this->manage[pos]).getRoomNumber() == x)
            return pos;
        if ((*this->manage[pos]).getRoomNumber() < x)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
}

void RoomMng::printBy()
{
    int s;
    cout << "\t\tIn Theo:" << endl;
    cout << "\n\t1. Trang thai phong dang trong";
    cout << "\n\t2. Tien thue phong";
    cout << "\n\t3. Loai phong";
    cout << "\n\tNhap Lua Chon Cua Ban (nhap 1 so ngoai 3 so o tren se in toan bo phong): ";
    cin >> s;
    cout << endl;
    switch (s)
    {
    case 1:
    {
        this->printAvailable();
        break;
    }
    case 2:
    {
        int s2;
        double d;
        cout << "\n\t1. So tien be hon";
        cout << "\n\t2. So tien lon hon";
        cout << "\n\tNhap lua chon cua ban: ";
        cin.ignore();
        cin >> s2;
        cout << "\n\tNhap so tien: ";
        cin >> d;
        cout << endl;
        switch (s2)
        {
        case 1:
        {
            drawaline();
            cout << endl;
            for (int i = 0; i < this->manage.size(); i++)
                if ((*this->manage[i]).getRent() < d)
                    cout << (*this->manage[i]) << endl;
            drawaline();
            break;
        }
        case 2:
        {
            drawaline();
            cout << endl;
            for (int i = 0; i < this->manage.size(); i++)
                if ((*this->manage[i]).getRent() > d)
                    cout << (*this->manage[i]) << endl;
            drawaline();
            break;
        }
        default:
        {
            this->printAll();
            break;
        }
        }
        break;
    }
    case 3:
    {
        int s3;
        bool b;
        cout << "\n\t1. Phong don/doi";
        cout << "\n\t2. Phong gia dinh";
        cout << "\n\tNhap loai phong: ";
        cin >> s3;
        cout << endl;
        if (s3 == 1)
            b = false;
        else if (s3 == 2)
            b = true;
        else
        {
            this->printAll();
            break;
        }
        for (int i = 0; i < this->manage.size(); i++)
            if ((*this->manage[i]).getType() == b)
                cout << (*this->manage[i]);
        break;
    }
    default:
    {
        this->printAll();
        break;
    }
    }
}
