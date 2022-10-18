#include <iostream>
using namespace std;
class Vector
{
    private:
        int*p;
        int length;
    public:
        Vector(int = 3, int = 2);
        ~Vector();
        int Length();
        void Length(int);
        int& operator[](const int&);
        Vector(const Vector&);
        const Vector& operator=(const Vector&);
};