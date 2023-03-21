#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    int count = 2;
    int num = 1;
    for (int i=1; i<=(n+1)/2; i++) {
        for (int j=1; j<=((n+1)/2)-i; j++) {
            cout<<"  ";
        }
        
        for (int k=1; k<=num; k++) {
            cout<<" "<<count;
            count++;
        }
        num += 2;
        cout<<endl;
    }
    
    num = num-4;
    
    for (int i=(n-1)/2; i>0; i--) {
        for (int j=1; j<=((n+1)/2)-i; j++) {
            cout<<"  ";
        }
        
        for (int k=1; k<=num; k++) {
            cout<<" "<<count;
            count++;
        }
        num -= 2;
        cout<<endl;
    }

    return 0;
}