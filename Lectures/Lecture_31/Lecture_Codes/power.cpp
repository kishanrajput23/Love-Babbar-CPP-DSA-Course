#include<iostream>
using namespace std;

int power(int n) {
    // base case
    if (n==0) {
        return 1;
    }

    // recursive relation
    return 2 * power(n-1);
}

int main() {

    int n;
    cout<<"Enter a number to find its power of 2 : ";
    cin>>n;

    int result = power(n);

    cout<<"Answer : "<<result<<endl;

    return 0;
}