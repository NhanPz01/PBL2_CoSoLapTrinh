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
    // void sort();
    void printAll();
    void printAvailable();
    void updateRoom(int);
};
