#include<iostream>
using namespace std;

void counting(int n) {
    // base case
    if (n==0) {
        return ;
    }

    // recursive relation
    counting(n-1);
    
    cout<<n<<endl;
}

int main() {

    int n;
    cout<<"Enter a number : ";
    cin>>n;

    counting(n);

    return 0;
}