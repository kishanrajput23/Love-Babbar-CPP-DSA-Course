#include<iostream>
using namespace std;

int main() {

    int arr[10] = {2,5,7};

    // ways to print address of first element of an array
    cout<<"Address of first element : "<<arr<<endl;
    cout<<"Address of first element : "<<&arr[0]<<endl;

    cout<<"The first element of array is : "<<arr[0]<<endl;

    cout<<"*arr : "<<*arr<<endl;
    cout<<"*arr + 1 : "<<*arr + 1<<endl;
    cout<<"*(arr+1) : "<<*(arr+1)<<endl;

    int i = 2;
    cout<<"i[arr] : "<<i[arr]<<endl;

    cout<<"Size of arr : "<<sizeof(arr)<<endl;
    int *ptr = &arr[0];
    cout<<"Size of ptr : "<<sizeof(ptr)<<endl;
    cout<<"Size of *ptr : "<<sizeof(*ptr)<<endl;
    cout<<"Size of &ptr : "<<sizeof(&ptr)<<endl;

    cout<<"&arr[0]: "<<&arr[0]<<endl;
    cout<<"&ptr : "<<&ptr<<endl;

    // arr = arr+1;     this will give an error message
    cout<<"Before incrementing [ptr] : "<<ptr<<endl;
    ptr = ptr+1;
    cout<<"After incrementing [ptr+1] : "<<ptr<<endl;

    return 0;
}