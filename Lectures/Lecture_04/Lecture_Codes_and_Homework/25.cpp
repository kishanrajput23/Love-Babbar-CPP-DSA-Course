#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    int num = n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=num; j++) {
            cout<<j;
        }
        for (int k=1; k<=(i-1)*2; k++) {
            cout<<"*";
        }
        for (int l=num; l>0; l--) {
            cout<<l;
        }
        num--;
        cout<<endl;
    }

    return 0;
}