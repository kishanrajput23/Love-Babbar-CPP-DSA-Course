#include<iostream>
using namespace std;

bool isPresent(int *arr, int size, int key) {
    if (size == 0) {
        return false;
    }

    if (arr[0] == key) {
        return true;
    }
    else {
        bool remainingArray = isPresent(arr+1, size-1, key);
        return remainingArray;
    }
}

int main() {

    int arr[] = {2,3,5,7,9};

    int size  = 5;

    int key  = 9;

    bool ans  = isPresent(arr, size, key);

    if (ans) {
        cout<<"Key Found"<<endl;
    }
    else {
        cout<<"Key Not Found"<<endl;
    }

    return 0;
}