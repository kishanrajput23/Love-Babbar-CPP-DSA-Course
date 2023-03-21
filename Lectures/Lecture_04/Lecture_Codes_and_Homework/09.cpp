#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    for (int i=1; i<=n; i++) {
        int num = i;
        for (int j=1; j<=i; j++) {
            cout<<num<<" ";
            num--;
        }
        cout<<endl;
    }

    return 0;
}