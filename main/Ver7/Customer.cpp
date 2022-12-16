#include "Customer.h"
#include <string>
Customer::Customer(){
}

Customer::Customer(string name, string address, string phone, string from_date, string to_date, double advance_payment, int booking_id)
    : name(name), address(address), phone(phone), from_date(from_date), to_date(to_date), advance_payment(advance_payment), booking_id(booking_id) {
}

Customer::Customer(Customer& c){
    this->name = c.name;
    this->address = c.address;
    this->phone = c.phone;
    this->from_date = c.from_date;
    this->to_date = c.to_date;
    this->advance_payment = c.advance_payment;
    this->booking_id = c.booking_id;
}

Customer::~Customer(){
}

void Customer::setName(string name){
    this->name = name;
}
void Customer::setAddress(string address){
    this->address = address;
}
void Customer::setPhone(string phone){
    this->phone = phone;
}
void Customer::setFromDate(string from_date){
    this->from_date = from_date;
}
void Customer::setToDate(string to_date){
    this->to_date = to_date;
}
void Customer::setAdvancePayment(double advance_payment){
    this->advance_payment = advance_payment;
}
void Customer::setBookingId(int booking_id){
    this->booking_id = booking_id;
}

string Customer::getName() const{
    return this->name;
}
string Customer::getAddress() const{
    return this->address;
}
string Customer::getPhone() const{
    return this->phone;
}
string Customer::getFromDate() const{
    return this->from_date;
}
string Customer::getToDate() const{
    return this->to_date;
}
double Customer::getAdvancePayment() const{
    return this->advance_payment;
}
int Customer::getBookingId() const{
    return this->booking_id;
}

ostream& operator<<(ostream& o, const Customer& c){
    o << "\nHo va Ten: " << c.getName() << "\nDia Chi: " << c.getAddress() << "\nNgay Check In: " << c.getFromDate() << "\nNgay Check Out: " << c.getToDate() << "\nTien Coc: " << c.getAdvancePayment() << "\nID: " << c.getBookingId() << endl;
    return o;
}
istream& operator>>(istream& i, Customer& c){
    string n,a,p,fd,td; double ap; int id;
	cout << "\nHo va Ten: ";
    cin.ignore();
    getline(i, n);
    c.setName(n);
    cout << "\nDia Chi: ";
    getline(i, a);
    c.setAddress(a);
    cout << "\nSDT: ";
    getline(i, p);
    c.setPhone(p);
    cout << "\nNgay Check In: ";
    getline(i, fd);
    c.setFromDate(fd);
    cout << "\nNgay Check Out: ";
    getline(i, td);
    c.setToDate(td);
    cout << "\nTien Coc: ";
    i >> ap;
    c.setAdvancePayment(ap);
    cout << "\nID: ";
    i >> id;
    c.setBookingId(id);
    return i;
}
Customer Customer::operator=(const Customer& c){
    this->name = c.name;
    this->address = c.address;
    this->phone = c.phone;
    this->from_date = c.from_date;
    this->to_date = c.to_date;
    this->advance_payment = c.advance_payment;
    this->booking_id = c.booking_id;
    return *this;
}
void Customer::update()
{
    cout << "Khach Hang" << endl;
    cout << "1. Ten Khach" << endl;
    cout << "2. Dia Chi" << endl;
    cout << "3. So Dien Thoai" << endl;
    cout << "4. Ngay Dat Phong" << endl;
    cout << "5. Ngay Tra Phong" << endl;
    cout << "6. Tien Dat Coc" << endl;
    cout << "7. BookingID" << endl;
    cout << "8. Lui lai" << endl;
    int s;
    cin >> s;
    switch (s)
    {
        case 1 : {
            cout << "Ten Khach : ";
            cin.ignore();
            getline(cin, this->name);
            break;
        }
        case 2 : {
            cout << "Dia Chi se duoc doi ve: ";
            cin.ignore();
            getline(cin, this->address);
            break;
        }
        case 3 : {
            cout << "So Dien Thoai se duoc doi ve: ";
            cin.ignore();
            getline(cin, this->phone);
            break;
        }
        case 4 : {
            cout << "Ngay Dat Phong se duoc doi ve: ";
            cin.ignore();
            getline(cin, this->from_date);
            break;
        }
        case 5 : {
            cout << "Ngay Tra Phong se duoc doi ve: ";
            cin.ignore();
            getline(cin, this->to_date);
            break;
        }
        case 6 : {
            cout << "Tien Dat Coc se duoc doi ve: ";
            cin >> this->advance_payment;
            break;
        }
        case 7 : {
            cout << "Booking ID se duoc doi ve: ";
            cin >> this->booking_id;
            break;
        }
        default : {
            break;
        }
    }
}
