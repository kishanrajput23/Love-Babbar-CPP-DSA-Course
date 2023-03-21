#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i-1; j++) {
            cout<<" ";
        }
        
        for (int k=i; k<=n; k++) {
            cout<<k;
        }
        cout<<endl;
    }

    return 0;
}