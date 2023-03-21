#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    for (int i=1; i<=n; i++) {
        for (int j=i; j<2*i; j++) {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}