#include<iostream>
using namespace std;

int main() {

    int num = 5;
    cout<<"num : "<<num<<endl;
    cout<<"Address of num : "<<&num<<endl;
    cout<<"-----------------------"<<endl;

    int *ptr = &num;
    cout<<"Address is (ptr) : "<<ptr<<endl;
    cout<<"Value is (*ptr) : "<<*ptr<<endl;
    cout<<"Size of num : "<<sizeof(num)<<endl;
    cout<<"Size of pointer (ptr) : "<<sizeof(ptr)<<endl;
    cout<<"-----------------------"<<endl;

    double d = 5.5;
    double *p = &d;
    cout<<"Address is (p) : "<<p<<endl;
    cout<<"Value is (*p) : "<<*p<<endl;    
    cout<<"Size of d : "<<sizeof(d)<<endl;
    cout<<"Size of pointer (p) : "<<sizeof(p)<<endl;
    cout<<"-----------------------"<<endl;

    // Ways to initialize pointer
    int i = 5;
    int *p1 = &i;
    cout<<"*p1 : "<<*p1<<endl;

    int *p2 = 0;
    p2 = &i;
    cout<<"*p2 : "<<*p2<<endl;
    cout<<"-----------------------"<<endl;

    // how to change existing value using pointer
    int j = 10;
    int *p3 = &j;
    cout<<"Before Incrementing (*p3) : "<<*p3<<endl;
    (*p3)++;
    cout<<"After Incrementing (*p3) : "<<*p3<<endl;
    cout<<"-----------------------"<<endl;

    // how to copy one pointer to another
    int *p4 = p3;
    cout<<"p3 : "<<p3<<" | p4 : "<<p4<<endl;
    cout<<"*p3 : "<<*p3<<" | *p4 "<<*p4<<endl;
    cout<<"-----------------------"<<endl;

    // in below example if we increment by 1 then it will point next interger value 
    cout<<"Before Incrementing (p4) : "<<p4<<endl;
    p4 = p4+1;
    cout<<"After Incrementing (p4) : "<<p4<<endl;
    cout<<"-----------------------"<<endl;

    return 0;
}