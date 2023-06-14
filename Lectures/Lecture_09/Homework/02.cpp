#include <iostream>

using namespace std;

int sumOfArray(int arr[], int size) {
    int sum = 0;
    for (int i=0; i<size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;
    
    int arr[size];
    
    cout<<"Enter the elements of the array : "<<endl;
    
    for (int i=0; i<size; i++) {
        cin>>arr[i];
    }
    
    cout<<"The sum of the array elements are : "<<sumOfArray(arr, size)<<endl;
    
    return 0;
}
