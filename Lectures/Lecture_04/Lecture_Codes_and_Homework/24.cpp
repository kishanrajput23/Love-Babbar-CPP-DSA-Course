#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n-i; j++) {
            cout<<" ";
        }
        int count = 1;
        for (int k=1; k<=i; k++) {
            cout<<count;
            count++;
        }
        for (int l=count-2; l>0; l--) {
            cout<<l;
        }
        cout<<endl;
    }

    return 0;
}