#include "RoomMng.h"
#include <vector>
#include <fstream>
#include <algorithm>

void drawaline()
{
    for (int i = 0; i < 100; i++)
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
            string name, address, phone, from_date, to_date;
            long double advance_payment;
            int booking_id;
            customersFile.ignore();
            getline(customersFile, name);
            (*cust).setName(name);
            getline(customersFile, address);
            (*cust).setAddress(address);
            customersFile >> phone;
            (*cust).setPhone(phone);

            customersFile >> from_date;
            (*cust).setFromDate(from_date);

            customersFile >> to_date;
            (*cust).setToDate(to_date);

            customersFile >> advance_payment;
			(*cust).setAdvancePayment(advance_payment);
            customersFile >> booking_id;
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

            else (*room).setEmptyRoom();
            this->manage.push_back(room);
        }
    }
    roomsFile.close();
    customersFile.close();
}

void RoomMng::saveRoomData(const string ROOMS){
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

void RoomMng::saveCustomersData(const string CUSTOMERS){
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
				customersFile << cust.getFromDate() << endl;
				customersFile << cust.getToDate() << endl;
				customersFile << cust.getAdvancePayment() << endl;
                customersFile << cust.getBookingId() << endl;
		}
	}
	customersFile.close();
}

void RoomMng::add()
{
    int size = this->manage.size();
    Room *a = new Room;
    this->manage.push_back(a);
    cin >> *(this->manage[size]);
    system("pause");
}
void RoomMng::add(Room *n)
{
    this->manage.push_back(n);
}
void RoomMng::removeAt(int index)
{
    int location = interpolationSearch(index);
    if (location != -1)
    {
        cout << "\nPhong se bi xoa !" << endl;
        cout << *this->manage[location];
        system("pause");
    }
    else
    {
        cout << "Phong khong ton tai !" << endl;
        while(location == -1)
        {
            cout << "Vui long nhap lai : ";
            cin >> index;
            location = this->interpolationSearch(index);
        }
        cout << "\nPhong se bi xoa !" << endl;
        cout << *this->manage[location];
        system("pause");
    }
    (this->manage).erase((this->manage).begin() + location);
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
    drawaline();
    cout << endl
         << "DANH SACH CAC PHONG : ";
    for (int i = 0; i < this->manage.size(); i++)
        cout << endl
             << *(this->manage[i]);
    drawaline();
    system("pause");
    system("cls");
}
void RoomMng::printRoom(int index)
{
    cout << endl
         << "Phong can tim la: " << *(this->manage[index]);
    system("pause");
}
void RoomMng::printAvailable()
{
    vector<int> a;
    system("cls");
    drawaline();
    cout << endl
         << "Tat Ca Cac Phong Hien Dang Trong: ";
    for (int i = 0; i < this->manage.size(); i++)
        if ((*this->manage[i]).getStatus() == 0)
        {
            a.push_back(i);
            cout << endl
                 << "Phong:" << (*this->manage[i]).getRoomNumber();
        }
    cout << endl;
    bool flag = true;
    do {
        drawaline();
        cout << "(1) Hien thong tin chi tiet" << endl
             << "(2) Tiep tuc" << endl
             << "Lua chon : ";
        int choose;
        cin >> choose;
        switch(choose) {
            case 1:
                for (int i = 0; i < a.size(); i++) {
                    cout  << (*this->manage[a[i]]) << endl;
                }
                break;
            default:
                flag = false;
                break;
        }
    } while(flag);
    drawaline();
}
void RoomMng::updateRoom(int index)
{

    int location = this->interpolationSearch(index);
    if (location != -1)
    {
        cout << "\nPhong se duoc cap nhat !" << endl;
        cout << *this->manage[location];

    }
    else
    {
        cout << "Phong khong ton tai !" << endl;
        while(location == -1)
        {
            cout << "Vui long nhap lai : ";
            cin >> index;
            location = this->interpolationSearch(index);
        }
        cout << "\nPhong se duoc cap nhat !" << endl;
        cout << *this->manage[location];
    }
    int s;
    // cout << "\t   Cap Nhat:" << endl;
    // cout << "\t1. So Phong" << endl;
    // cout << "\t2. Loai Phong" << endl;
    // cout << "\t3. Tien Thue Phong" << endl;
    // cout << "\t4. Khach Hang" << endl;
    bool flag = true;
    do {
        cout << "----------CAP NHAT----------" << endl
            << "(1) So phong" << endl
            << "(2) Loai phong" << endl
            << "(3) Tien thue phong" << endl
            << "(4) Khach hang" << endl
            << "(5) Lui lai" << endl
            << "Lua chon : ";
        int choose;
        cin >> choose;
        switch (choose)
        {
            case 1 : {
                int i;
                cout << "\tNhap So Phong Muon Doi: \n";
                cin >> i;
                (*this->manage[location]).setRoomNumber(i);
                break;
            }
            case 2 : {
                bool i;
                cout << "\tNhap 0: Phong 2 Nguoi";
                cout << "\n\tNhap 1: Phong Gia Dinh\n";
                cin >> i;
                (*this->manage[location]).setType(i);
                break;
            }
            case 3 : {
                long double i;
                cout << "\tNhap Tien Thue Moi: \n";
                cin >> i;
                (*this->manage[location]).setRent(i);
                break;
            }
            case 4 : {
                (*(*this->manage[location]).getCustomer()).update();
                break;
            }
            default : {
                flag = false;
                break;
            }
        }
    } while (flag);
}
int RoomMng::interpolationSearch(int x)
{
    if ((*this->manage[0]).getRoomNumber() == x)
        return 0;
    int lo = 0, hi = (this->manage.size())-1;
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
        long double d;
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

// void swap(int* a, int* b)
// {
//     int t = *a;
//     *a = *b;
//     *b = t;
// }

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int RoomMng::partition(int low, int high)
{
    int pivot = (*this->manage[high]).getRoomNumber(); // pivot
    int i
        = (low - 1); // Index of smaller element and indicates
                 // the right position of pivot found so far

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if ((*this->manage[j]).getRoomNumber() < pivot) {
            i++; // increment index of smaller element
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
    Sort(0, manage.size()-1);
}

int RoomMng::getSize(){
    return manage.size();
}

void RoomMng::checkIn()
{
    system("cls");
    this->printAvailable();
    cout << "\nNhap so phong muon checkin : ";
    int sp;
    cin >> sp;
    int location = this->interpolationSearch(sp);
    cout << "location : " << location;
    if (location != -1)
    {
        cout << "\nPhong se duoc check in !" << endl;
        cout << *this->manage[location];
    }
    else
    {
        cout << "Phong khong ton tai !" << endl;
        while(location == -1)
        {
            cout << "Nhap lai : ";
            cin >> sp;
            location = this->interpolationSearch(sp);
        }
        cout << "\nPhong se duoc check in !" << endl;
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
    cout << "So phong check out : ";
    int sp;
    cin >> sp;
    int location = this->interpolationSearch(sp);
    if (location != -1)
    {
        cout << "\nPhong se duoc check out !" << endl;
        cout << *this->manage[location];
    }
    else
    {
        cout << "Phong khong ton tai !" << endl;
        while(location == -1)
        {
            cout << "Nhap lai : ";
            cin >> sp;
            location = this->interpolationSearch(sp);
        }
        cout << "\nPhong se duoc check out !" << endl;
        cout << *this->manage[location];
    }
    cout << "\nNhap so ngay thue phong : ";
    int days;
    cin >> days;
    cout << fixed << "\nBill : " << this->getBill(days, location) << endl;
    this->manage[location]->removeCust();
    system("pause");
}

long double RoomMng::getBill(int days, int location)
{
    if (this->manage[location]->getCustomer()->getAdvancePayment() > (this->manage[location]->getRent() * days))
    return 0;
    return (days * this->manage[location]->getRent()) - this->manage[location]->getCustomer()->getAdvancePayment();
}
