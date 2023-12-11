#include<iostream>
using namespace std;

int fibonacci(int n) {
    if (n==0) {
        return 0;
    }

    if (n==1) {
        return 1;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {

    int n;
    
    cout<<"Enter a nth term to find its fibonacci value : ";
    cin>>n;

    cout<<"The number is : "<<fibonacci(n)<<endl;

    return 0;
}