#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    char ch = 'A';
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout<<ch<<" ";
            ch += 1;
        }
        cout<<endl;
    }

    return 0;
}