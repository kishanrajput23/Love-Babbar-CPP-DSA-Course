#include<iostream>
using namespace std;

int main() {
    char ch[20];

    cout<<"Enter your name : ";
    cin>>ch;

    ch[3] = '\0';

    cout<<"Your name is : "<<ch<<endl;

    return 0;
}