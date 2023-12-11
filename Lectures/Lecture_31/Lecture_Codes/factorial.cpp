#include<iostream>
using namespace std;

int factorial(int n) {
    // base case
    if (n==0) {
        return 1;
    }

    // recursive relation
    return n * factorial(n-1);
}

int main() {

    int n;
    cout<<"Enter a number to find its factorial : ";
    cin>>n;

    int result = factorial(n);

    cout<<"Answer : "<<result<<endl;

    return 0;
}