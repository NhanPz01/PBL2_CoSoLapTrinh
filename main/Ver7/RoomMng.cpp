#include "RoomMng.h"
#include <vector>
#include <fstream>
#include <algorithm>

void drawALine()
{
    for (int i = 0; i < 61; i++)
    {
        cout << "=";
    }
    cout << endl;
}

void RoomMng::getRoomData(const string ROOMS, const string CUSTOMERS)
{
    ifstream roomsFile;
    ifstream customersFile;
    roomsFile.open(ROOMS);
    customersFile.open(CUSTOMERS);
    Date from_date, to_date;
    if (!roomsFile.is_open())
    {
        cout << "Unable to get the rooms information" << endl;
    }
    else
    {

        vector<Customer *> customers;
        int numberOfCustomers;
        customersFile >> numberOfCustomers;
        for (int i = 0; i < numberOfCustomers; i++)
        {
            Customer *cust = new Customer;
            string name, address, phone;
            int d1, m1, y1, d2, m2, y2;
            long double advance_payment;
            int booking_id;
            customersFile.ignore();
            getline(customersFile, name);
            getline(customersFile, address);
            getline(customersFile, phone);
            customersFile >> d1;
            customersFile >> m1;
            customersFile >> y1;
            customersFile >> d2;
            customersFile >> m2;
            customersFile >> y2;
            customersFile >> advance_payment;
            customersFile >> booking_id;

            from_date.setDay(d1);
            from_date.setMonth(m1);
            from_date.setYear(y1);
            to_date.setDay(d2);
            to_date.setMonth(m2);
            to_date.setYear(y2);

            (*cust).setName(name);
            (*cust).setAddress(address);
            (*cust).setPhone(phone);
            (*cust).setFromDate(from_date);
            (*cust).setToDate(to_date);
            (*cust).setAdvancePayment(advance_payment);
            (*cust).setBookingId(booking_id);
            customers.push_back(cust);
        }
        int roomNumber;
        roomsFile >> roomNumber;
        for (int i = 0; i < roomNumber; i++)
        {
            Room *room = new Room;
            bool status, type;
            int roomNumber;
            long double rent;
            roomsFile >> status;
            (*room).setStatus(status);
            roomsFile >> roomNumber;
            (*room).setRoomNumber(roomNumber);
            roomsFile >> rent;
            (*room).setRent(rent);
            roomsFile >> type;
            (*room).setType(type);
            if (i < numberOfCustomers)
                (*room).setCustomer(customers[i]);

            else
                (*room).setEmptyRoom();
            this->manage.push_back(room);
        }
    }
    roomsFile.close();
    customersFile.close();
}

void RoomMng::saveRoomData(const string ROOMS)
{
    ofstream roomsFile;
    roomsFile.open(ROOMS);
    if (!roomsFile.is_open())
    {
        cout << "Unable to save the rooms information" << endl;
    }
    else
    {

        roomsFile << manage.size() << endl;
        for (int i = 0; i < manage.size(); i++)
        {
            roomsFile << (*this->manage[i]).getStatus() << endl;
            roomsFile << (*this->manage[i]).getRoomNumber() << endl;
            roomsFile << (*this->manage[i]).getRent() << endl;
            roomsFile << (*this->manage[i]).getType() << endl;
        }
    }
    roomsFile.close();
}

void RoomMng::saveCustomersData(const string CUSTOMERS)
{
    ofstream customersFile;
    customersFile.open(CUSTOMERS);
    if (!customersFile.is_open())
    {
        cout << "Unable to save the customers data" << endl;
    }
    else
    {
        customersFile << manage.size() << endl;
        for (int i = 0; i < manage.size(); i++)
        {
            Customer cust = *((*this->manage[i]).getCustomer());
            customersFile << cust.getName() << endl;
            customersFile << cust.getAddress() << endl;
            customersFile << cust.getPhone() << endl;
            customersFile << cust.getFromDate().getDay() << endl;
            customersFile << cust.getFromDate().getMonth() << endl;
            customersFile << cust.getFromDate().getYear() << endl;
            customersFile << cust.getToDate().getDay() << endl;
            customersFile << cust.getToDate().getMonth() << endl;
            customersFile << cust.getToDate().getYear() << endl;
            customersFile << cust.getAdvancePayment() << endl;
            customersFile << cust.getBookingId() << endl;
        }
    }
    customersFile.close();
}

void RoomMng::add()
{   
    cout << "--------------------------THEM PHONG-------------------------";
    int anotherNumber;
    int size = this->manage.size();
    Room *a = new Room;
    cin >> *a;
    // cin >> *(this->manage[size]);
    while (interpolationSearch(a->getRoomNumber()) != -1)
    {
        cout << "SO PHONG NAY DA TON TAI VUI LONG NHAP LAI: ";
        cin >> anotherNumber;
        a->setRoomNumber(anotherNumber);
    }
    this->manage.push_back(a);
    system("pause");
}

void RoomMng::add(Room *n)
{
    this->manage.push_back(n);
}

void RoomMng::removeAt(int index)
{
    int location = interpolationSearch(index);
    while (location == -1)
    {
        cout << "Phong khong ton tai !" << endl;
        cout << "Vui long nhap lai : ";
        cin >> index;
        location = interpolationSearch(index);
    }
    cout << "\nPHONG SE BI XOA: " << endl;
    cout << *this->manage[location];
    int choose;
    cout << "\t(1) XOA PHONG NAY" << endl
         << "\t(2) LUI LAI" << endl
         << "LUA CHON : ";
    cin >> choose;
    switch (choose)
    {
    case 1:
    {
        (this->manage).erase((this->manage).begin() + location);
        break;
    }
    default:
        break;
    }
}

void RoomMng::removeFirst()
{
    removeAt(0);
}

void RoomMng::removeLast()
{
    removeAt(this->manage.size() - 1);
}

void RoomMng::printAll()
{
    system("cls");
    drawALine();
    cout << "DANH SACH CAC PHONG : ";
    cout << endl;
    for (int i = 0; i < this->manage.size(); i++)
        cout << endl
             << *(this->manage[i]);
    drawALine();
    system("pause");
    system("cls");
}

void RoomMng::printRoom(int index)
{
    cout << endl
         << "PHONG CAN TIM LA: " << *(this->manage[index]);
    system("pause");
}

void RoomMng::printAvailable()
{
    vector<int> a;
    system("cls");
    drawALine();

    cout << "\t\tTAT CA CAC PHONG HIEN DANG TRONG";
    for (int i = 0; i < this->manage.size(); i++)
        if ((*this->manage[i]).getStatus() == 0)
        {
            a.push_back(i);
            cout << endl
                 << "\tPHONG: " << (*this->manage[i]).getRoomNumber();
        }
    cout << endl;
    bool flag = true;
    do
    {
        drawALine();
        cout << "(1) HIEN THI CHI TIET" << endl
             << "(..) TIEP TUC" << endl
             << "LUA CHON : ";
        int choose;
        cin >> choose;
        switch (choose)
        {
        case 1:
            system("cls");
            cout << "\tTHONG TIN TAT CA CAC PHONG HIEN DANG TRONG LA: " << endl;
            for (int i = 0; i < a.size(); i++)
            {
                cout << (*this->manage[a[i]]) << endl;
            }
            break;
        default:
            flag = false;
            break;
        }
    } while (flag);
    drawALine();
}

void RoomMng::updateRoom(int index)
{

    int location = this->interpolationSearch(index);
    if (location != -1)
    {
        cout << "\nPHONG SE DUOC CAP NHAT: " << endl;
        cout << *this->manage[location];
    }
    else
    {
        cout << "PHONG KHONG TON TAI!!" << endl;
        while (location == -1)
        {
            cout << "VUI LONG NHAP LAI: ";
            cin >> index;
            location = this->interpolationSearch(index);
        }
        cout << "\nPHONG SE DUOC CAP NHAT: " << endl;
        cout << *this->manage[location];
    }
    int s;
    bool flag = true;
    do
    {
        system("cls");
        cout << "\t\t-----------CAP NHAT-----------" << endl
             << "\t(1) So phong" << endl
             << "\t(2) Loai phong" << endl
             << "\t(3) Tien thue phong" << endl;
        if (this->manage[location]->getStatus() == true)
        {
            cout << "\t(4) Khach hang" << endl;
        }
            cout << "\t(..) Lui lai" << endl
             << "Lua chon : ";
        int choose;
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            int i;
            cout << "\tNHAP SO PHONG MUON DOI: \n";
            cin >> i;
            (*this->manage[location]).setRoomNumber(i);
            break;
        }
        case 2:
        {
            bool i;
            cout << "\tNHAP 0: PHONG DOI/ NHAP 1: PHONG GIA DINH";
            cin >> i;
            (*this->manage[location]).setType(i);
            break;
        }
        case 3:
        {
            long double i;
            cout << "\tNHAP TIEN THUE MOI: \n";
            cin >> i;
            (*this->manage[location]).setRent(i);
            break;
        }
        case 4:
        {
            if (this->manage[location]->getStatus() == false)
                return;
            (*(*this->manage[location]).getCustomer()).update();
            break;
        }
        default:
        {
            flag = false;
            break;
        }
        }
    } while (flag);
    system("pause");
    system("cls");
}

int RoomMng::interpolationSearch(int x)
{
    if ((*this->manage[0]).getRoomNumber() == x)
        return 0;
    int lo = 0, hi = (this->manage.size()) - 1;
    while (lo <= hi && x >= (*this->manage[lo]).getRoomNumber() && x <= (*this->manage[hi]).getRoomNumber())
    {
        if (lo == hi)
        {
            if ((*this->manage[lo]).getRoomNumber() == x)
                return lo;
            return -1;
        }
        int pos = lo + (((long double)(hi - lo) /
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
    cout << "\t\tIN THEO:" << endl;
    cout << "\n\t(1) Trang thai phong dang trong";
    cout << "\n\t(2) Tien thue phong";
    cout << "\n\t(3) Loai phong";
    cout << "\n\t(..) QUAY LAI";
    cout << "\n\tLUA CHON:  ";
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
        long double d;
        cout << "\n\t(1) So tien be hon";
        cout << "\n\t(2) So tien lon hon";
        cout << "\n\tLUA CHON: ";
        cin.ignore();
        cin >> s2;
        cout << "\n\tNHAP SO TIEN: ";
        cin >> d;
        cout << endl;
        switch (s2)
        {
        case 1:
        {
            drawALine();
            cout << endl;
            for (int i = 0; i < this->manage.size(); i++)
                if ((*this->manage[i]).getRent() < d)
                    cout << (*this->manage[i]) << endl;
            drawALine();
            break;
        }
        case 2:
        {
            drawALine();
            cout << endl;
            for (int i = 0; i < this->manage.size(); i++)
                if ((*this->manage[i]).getRent() > d)
                    cout << (*this->manage[i]) << endl;
            drawALine();
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
        cout << "\n\t(1) Phong doi";
        cout << "\n\t(2) Phong gia dinh";
        cout << "\n\tLUA CHON: ";
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


int RoomMng::partition(int low, int high)
{
    int pivot = (*this->manage[high]).getRoomNumber();
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++) {
        if ((*this->manage[j]).getRoomNumber() < pivot) {
            i++;
            swap((this->manage[i]), (this->manage[j]));
        }
    }
    swap((this->manage[i + 1]), (this->manage[high]));
    return (i + 1);
}
void RoomMng::Sort(int low, int high)
{   
    if (low < high) {
        int pi = partition(low, high);
        Sort(low, pi - 1);
        Sort(pi + 1, high);
    }
}

void RoomMng::Sort(){
    Sort(0, manage.size() - 1);
}

int RoomMng::getSize(){
    return manage.size();
}

void RoomMng::checkIn()
{
    system("cls");
    this->printAvailable();
    cout << "--------------------------CHECK IN---------------------------";
    cout << "\nNHAP SO PHONG MUON CHECKIN: ";
    int sp;
    cin >> sp;
    int location = this->interpolationSearch(sp);
    if (location != -1)
    {   
        cout << "\nPHONG SE DUOC CHECKIN:" << endl;
        cout << *this->manage[location];
    }
    else
    {
        cout << "PHONG KHONG TON TAI HOAC DA CO NGUOI" << endl;
        while (location == -1)
        {
            cout << "VUI LONG NHAP LAI : ";
            cin >> sp;
            location = this->interpolationSearch(sp);
        }
        cout << "\nPHONG SE DUOC CHECKIN:" << endl;
        cout << *this->manage[location];
    }
    Customer *cust = new Customer();
    cin >> *cust;
    this->manage[location]->addCust(cust);
    system("pause");
}

void RoomMng::checkOut()
{
    system("cls");
    cout << "--------------------------CHECK OUT--------------------------";
    cout << "NHAP SO PHONG MUON CHECKOUT: ";
    int sp;
    cin >> sp;
    int location = this->interpolationSearch(sp);
    if (location != -1 && this->manage[location]->getStatus() == 1)
    {
        cout << "\nPHONG SE DUOC CHECKOUT:" << endl;
        cout << *this->manage[location];
    }
    else
    {
        cout << "PHONG KHONG TON TAI!!!" << endl;
        while (location == -1)
        {
            cout << "VUI LONG NHAP LAI: ";
            cin >> sp;
            location = this->interpolationSearch(sp);
        }
        cout << "\nPHONG SE DUOC CHECKOUT:" << endl;
        cout << *this->manage[location];
    }
    int days = this->manage[location]->getCustomer()->dateDiff();

    cout << fixed << "\nBill : " << this->getBill(days, location) << endl;
    this->manage[location]->removeCust();
    system("pause");
}

long double RoomMng::getBill(int days, int location)
{
    if (this->manage[location]->getCustomer()->getAdvancePayment() >
        (this->manage[location]->getRent() * days)
    )
        return 0;
    return (days * this->manage[location]->getRent()) -
             this->manage[location]->getCustomer()->getAdvancePayment();
}
