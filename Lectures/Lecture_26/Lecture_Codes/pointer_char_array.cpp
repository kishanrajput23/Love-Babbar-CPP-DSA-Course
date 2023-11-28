#include<iostream>
using namespace std;

int main() {

    int arr[5] = {1,2,3,4,5};
    cout<<"arr : "<<arr<<endl;

    char ch[6] = "abcde";
    cout<<"ch : "<<ch<<endl;        //prints entire string

    char *c = &ch[0];
    cout<<"c : "<<c<<endl;      //prints entire string

    char temp = 'z';
    char *p = &temp;
    cout<<"p : "<<p<<endl;      // prints garbage value after z till it finds a null character

    return 0;
}