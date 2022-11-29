#include "Room.h"
#include <iostream>
using namespace std;
// ostream& operator<<(ostream &o, const Room& r){
// 	o << "Room number: ";
// 	o <<  r.getRoomNumber() << endl;
// 	o << "Room status: ";
// 	o <<  r.getStatus() << endl;
// 	o << "Room type: ";
// 	o <<  r.getType() << endl;
// 	o << "Room rent: ";
// 	o <<  r.getRent() << endl;
// 	return o;
// }

// istream& operator>>(istream &i, Room& r){
// 	int n; bool s,t; double p;
// 	cout << "Room number: ";
// 	i >> n;
// 	r.setRoomNumber(n);
// 	cout << "Room status: ";
// 	i >> s;
// 	r.setStatus(s);
// 	cout << "Room type: ";
// 	i >> t;
// 	r.setType(t);
// 	cout << "Room rent: ";
// 	i >> r;
// 	r.setRent(p);
// 	return i;
// }
int main(){
	Room a;
	cin >> a;
	cout << a;
}