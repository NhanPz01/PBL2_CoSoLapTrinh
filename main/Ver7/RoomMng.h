#include "Room.h"
#include <vector>
using namespace std;
class RoomMng{
private:
    vector<Room*> manage;
public:
    void add();
    void add(Room*);
    void remove(int);
    void printAll();
    void printAvailable();
    // void printBy()
    void updateRoom(int);
    // void addCust(int);
    void addCust(int, Customer*);
};
