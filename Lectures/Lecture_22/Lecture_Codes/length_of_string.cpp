#include<iostream>
using namespace std;

int getLength(char name[]) {
    int count = 0;
    for (int i=0; name[i]!='\0'; i++) {
        count++;
    }
    return count;
}

int main() {

    char ch[20];

    cout<<"Enter your name : ";
    cin>>ch;

    cout<<"Your name is : "<<ch<<endl;
    cout<<"The length of your name is : "<<getLength(ch)<<endl;

    return 0;
}