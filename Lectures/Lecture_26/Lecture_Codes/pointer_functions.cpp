#include<iostream>
using namespace std;

void print(int *p) {

    cout<<*p<<endl;
}

void update(int *p) {

    p = p+1;
}

int getSum(int arr[], int n) {      //or int getSum(int *arr, int n) {  
    cout<<"Size of arr inside function : "<<sizeof(arr)<<endl;      // this will return 8 as arr passed as a pointer here
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += arr[i];      //or sum += i[arr];
    }
    return sum;
}

int main() {

    int val = 5;
     
    int *p = &val;

    print(p); 

    cout<<"Before update p : "<<p<<endl;
    update(p);
    cout<<"After update p : "<<p<<endl;

    int arr[5] = {1,2,3,4,5};
    int sum = getSum(arr, 5);
    cout<<"Size of arr outside function : "<<sizeof(arr)<<endl;
    cout<<"Sum is : "<<sum<<endl;

    return 0;
}