#include<iostream>
#include<array>
using namespace std;

int main() {

    int basic[3] = {1,2,3};
    array<int, 5> arr = {1,2,3,4,5};

    int size = arr.size();
    cout<<"The size of the array is : "<<size<<endl;

    cout<<"The array elements are : ";
    for (int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Element at 2nd index is : "<<arr.at(2)<<endl;

    cout<<"Arrays is empty or not : "<<arr.empty()<<endl;

    cout<<"First Element : "<<arr.front()<<endl;

    cout<<"Last Element : "<<arr.back()<<endl;

    // below command will fill array with given number and replace all elements
    arr.fill(4);
    cout<<"The array elements are : ";
    for (int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}