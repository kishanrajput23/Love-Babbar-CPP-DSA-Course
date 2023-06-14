#include <iostream>
#include<math.h>

using namespace std;

int bitConvertor(int n) {
    int ans  = 0;
    int i = 0;
    while (n != 0 ) {
        int bit  = n & 1;
        ans = (bit * pow(10, i) ) + ans;
        n = n >> 1;
        i++;
    }
    return ans;
}

int bitCount(int n) {
    int num = bitConvertor(n);
    int count = 0;
    
    while (num != 0) {
        int rem = num%10;
        if (rem == 1) {
            count++;
        }
        num /= 10;
    }
    return count;
}

int main()
{
    int a, b;
    
    cout<<"Enter the value of a : ";
    cin>>a;
    
    cout<<"Enter the value of b : ";
    cin>>b;
    
    int ans = bitCount(a) + bitCount(b);
    cout<<"The total number of set bit of 1 is : "<<ans<<endl;
    return 0;
}
