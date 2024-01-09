#include<iostream>
using namespace std;

int add(int a, int b) {
    return a+b;
}

int add(int a, int b, int c) {
    return a+b+c;
}

int main() {

    cout<<add(2,5)<<endl;
    cout<<add(5,7,9)<<endl;

    return 0;
}