#include<iostream>
using namespace std;

void reverseString(char name[], int n) {
    int s = 0;
    int e = n-1;

    while (s<e) {
        swap(name[s++], name[e--]);
    }
}

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

    int len = getLength(ch);
    cout<<"The length of your name is : "<<len<<endl;

    reverseString(ch, len);
    cout<<"The reverse of your name is : "<<ch<<endl;

    return 0;
}