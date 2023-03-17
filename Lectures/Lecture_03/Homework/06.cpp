#include <iostream>

using namespace std;

int main()
{
    int n;
    int i=2;
    int sum = 0;
    
    cout<<"Enter a number : ";
    cin>>n;
    
    while (i<=n) {
        if (i%2==0) {
            sum = sum + i;
        }
        i = i+1;
    }
    cout<<"The sum of even numbers are : "<<sum<<endl;
    
    return 0;
}
