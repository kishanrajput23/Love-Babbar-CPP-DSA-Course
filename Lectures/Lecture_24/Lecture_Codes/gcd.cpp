#include<iostream>
using namespace std;

// How to find Greatest Common Divisor (GCD) by using Euclid Algorithm
int gcd(int a, int b) {
    if (a==0) {
        return b;
    }

    if (b==0) {
        return a;
    }

    while(a!=b) {
        if (a>b) {
            a = a-b;
        }
        else {
            b = b-a;
        }
    }
    return a;
}

int main() {

    int a,b;

    cout<<"Enter two numbers to find GCD : ";
    cin>>a>>b;

    cout<<"The GCD of "<<a<<" & "<<b<<" is "<<gcd(a,b)<<endl;

    return 0;
}