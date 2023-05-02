// decimal to binary conversion

#include<iostream>
#include<math.h>

using namespace std;

int main() {
    
    int n;
    int ans=0, i=0;
    cout<<"Decimal Number : ";
    cin>>n;
    
    while (n!=0) {
        int bit = n&1;
        
        ans = bit * pow(10, i) + ans;
        
        n = n>>1;
        i++;
    }
    
    cout<<"Binary Number : "<<ans<<endl;
}