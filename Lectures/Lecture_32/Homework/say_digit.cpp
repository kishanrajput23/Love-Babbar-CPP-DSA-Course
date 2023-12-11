#include<iostream>
using namespace std;

void sayDigit(int n, string arr[]) {

    if (n==0) {
        return ;
    }

    int digit = n%10;
    n /= 10;

    sayDigit(n, arr);

    cout<<arr[digit]<<" ";
}

int main() {
    int n;

    cout<<"Enter a number : ";
    cin>>n;

    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    sayDigit(n, arr);

    return 0;
}