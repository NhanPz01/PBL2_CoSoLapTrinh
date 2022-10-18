#include <bits/stdc++.h>
using namespace std;
#define PI 3.14

void f(int x){
    static int y = x;
    return y++;
}
int main(){
 cout << f(1) << f(1);
}