#include<iostream>
using namespace std;

int main() {

    int i = 5;
    int *p1 = &i;
    int **p2 = &p1;

    cout<<"Printing Values : "<<endl;
    cout<<"i : "<<i<<endl;
    cout<<"*p1 : "<<*p1<<endl;
    cout<<"**p2 : "<<**p2<<endl;

    cout<<endl<<"Printing Address : "<<endl;
    cout<<"p1 : "<<p1<<endl;
    cout<<"&i : "<<&i<<endl;
    cout<<"--------------"<<endl;
    cout<<"p2 : "<<p2<<endl;
    cout<<"&p1 : "<<&p1<<endl;

    cout<<endl<<"Ways to print values : "<<endl;
    cout<<"i : "<<i<<endl;
    cout<<"*p1 : "<<*p1<<endl;
    cout<<"**p2 : "<<**p2<<endl;

    return 0;
}