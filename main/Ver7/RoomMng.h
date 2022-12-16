#include "Room.h"
#include <vector>
using namespace std;
class RoomMng{
private:
    vector<Room*> manage;
public:
    void add();
    void add(Room*);
    void getRoomData(const string, const string);
    void saveRoomData(const string);
    void saveCustomersData(const string);
    void removeAt(int);
    void removeFirst();
    void removeLast();
    void printAll();
    void printRoom(int);
    void printAvailable();
    void Sort(int,int);
    void Sort();
    int interpolationSearch(int);
    // void printBy()
    void updateRoom(int);
    // void addCust(int);
    void addCust(int, Customer*);
    void printBy();
    int partition(int, int);
    int getSize();
    void checkIn();
    void checkOut();
    long double getBill(int, int);
};
