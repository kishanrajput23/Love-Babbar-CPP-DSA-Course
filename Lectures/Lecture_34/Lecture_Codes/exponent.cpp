#include<iostream>
using namespace std;

int exponent(int a, int b) {

    // base case
    if (b==0) {
        return 1;
    }

    if (b==1) {
        return a;
    }

    int ans = exponent(a, b/2);

    if (b%2==0) {
        return ans * ans;
    }
    else {
        return a * ans * ans;
    }
}

int main() {

    int a, b;

    cout<<"Enter digit value : ";
    cin>>a;

    cout<<"Enter exponent value : ";
    cin>>b;

    cout<<exponent(a, b)<<endl;

    return 0;
}