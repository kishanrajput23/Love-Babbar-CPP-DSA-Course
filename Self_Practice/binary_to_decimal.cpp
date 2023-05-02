// binary to decimal conversion

#include<iostream>
#include<math.h>

using namespace std;

int main() {
    
    int n;
    int ans=0, i=0;
    cout<<"Binary Number : ";
    cin>>n;
    
    while(n!=0) {
        int digit = n%10;
        
        if (digit == 1) {
            ans = digit * pow(2, i) + ans;
        }
        
        n /= 10;
        i++;
    }
    
    cout<<"Decimal Number : "<<ans<<endl;
}