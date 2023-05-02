// negative decimal to binary conversion

#include<iostream>
#include<math.h>

using namespace std;

int main() {
    
    long long int n;
    unsigned long long int i=0, ans=0;
    
    cout<<"Decimal Number : ";
    cin>>n;
    
    if (n<0) {
        n = pow(2, 16) + n;
    }
    
    cout<<"n : "<<n<<endl;
    
    while (n!=0) {
        int bit = n&1;
        
        ans = bit * pow(10, i) + ans;
        
        n = n>>1;
        i++;
    }
    
    cout<<"Binary Number : "<<ans<<endl;
}