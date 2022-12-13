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
    void remove(int);
    void removeFirst();
    void removeLast();
    void printAll();
    void printRoom(int);
    void printAvailable();
    void Sort();
    int interpolationSearch(int);
    // void printBy()
    void updateRoom(int);
    // void addCust(int);
    void addCust(int, Customer*);
    void printBy();
};
