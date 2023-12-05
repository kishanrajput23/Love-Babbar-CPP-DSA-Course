#include<iostream>
using namespace std;

/*
inline functionw conditons:

if our function contain only one liner code then compiler accept our inline function

if our function contain only two or three liner code then it depends on compiler whether it accept or reject

if our function contain more than 3 liner code then compiler reject our inline function
*/

inline int getMax(int& a, int& b) {
    return (a>b) ? a : b;
}

int main() {

    int a = 1, b = 2;

    int ans  = getMax(a, b);
    cout<<"Max : "<<ans<<endl;

    a += 3;
    b += 1;

    ans  = getMax(a, b);
    cout<<"Max : "<<ans<<endl;

    return 0;
}