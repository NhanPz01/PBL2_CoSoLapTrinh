#include <iostream>
#include "Point.h"
#include "Vector.h"
#include "Number.h"
using namespace std;
int main(){
    Vector v1(3,2);
    Vector v2(v1);
    Vector v3 = v1;
    Vector v4;
    v4 = v1;
    return 0;
}

