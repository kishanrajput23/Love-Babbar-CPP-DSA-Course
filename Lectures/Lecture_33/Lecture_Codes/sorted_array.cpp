#include<iostream>
using namespace std;

bool isSorted(int *arr, int size) {
    if (size == 0 || size == 1) {
        return true;
    }

    if (arr[0]>arr[1]) {
        return false;
    }
    else {
        bool remainingArray = isSorted(arr+1, size-1);
        return remainingArray;
    }
}

int main() {

    int arr[] = {2,3,5,7,9};

    int size  = 5;

    bool ans  = isSorted(arr, size);

    if (ans) {
        cout<<"Array is sorted"<<endl;
    }
    else {
        cout<<"Array is not sorted"<<endl;
    }

    return 0;
}