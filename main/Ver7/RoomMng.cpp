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
            double advance_payment;
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
            double rent;
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
			Customer cust = (*this->manage[i]).getCustomer();
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
}
void RoomMng::add(Room *n)
{
    this->manage.push_back(n);
}
void RoomMng::removeAt(int index)
{

    (this->manage).erase((this->manage).begin() + index);
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