#include <iostream>

using namespace std;

int main()
{
    char ch;
    cout<<"Enter a character value : ";
    cin>>ch;
    
    if (ch >= '0' && ch <= '9') {
        cout<<"This is numeric character."<<endl;
    }
    else if (ch >= 'a' &&  ch <= 'z') {
        cout<<"This is lowercase character."<<endl;
    }
    else {
        cout<<"This is uppercase character."<<endl;
    }

    return 0;
}