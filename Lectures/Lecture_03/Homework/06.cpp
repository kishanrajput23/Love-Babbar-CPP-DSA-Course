#include <iostream>

using namespace std;

int main()
{
    int n;
    int i=0;
    int sum = 0;
    
    cout<<"Enter a number : ";
    cin>>n;
    
    while (i<=n) {
        sum = sum + i;
        i = i+2;
    }
    cout<<"The sum of even numbers are : "<<sum<<endl;
    
    return 0;
}