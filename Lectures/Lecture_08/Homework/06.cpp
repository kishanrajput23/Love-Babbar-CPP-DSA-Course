#include <iostream>
#include<math.h>

using namespace std;

int nthFibonacci(int n) {
    
    if (n <= 1) {
        return n;
    }
        
    int previous = 0;
    int current = 1;
    
    for (int i=2; i<=n; i++) {
        int next = previous + current;
        
        previous = current;
        current = next;
    }
    return current;
}

int main()
{
    int n;
    
    cout<<"Enter the value of n : ";
    cin>>n;
    
    cout<<"The "<<n<<"th Fibonacci number is : "<<nthFibonacci(n)<<endl;
    
    return 0;
}
