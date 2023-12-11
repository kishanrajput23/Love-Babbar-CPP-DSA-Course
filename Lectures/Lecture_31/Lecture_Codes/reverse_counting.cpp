#include<iostream>
using namespace std;

void counting(int n) {
    // base case
    if (n==0) {
        return ;
    }
    
    cout<<n<<endl;

    // recursive relation
    counting(n-1);
}

int main() {

    int n;
    cout<<"Enter a number : ";
    cin>>n;

    counting(n);

    return 0;
}