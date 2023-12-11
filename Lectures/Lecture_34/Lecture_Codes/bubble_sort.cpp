#include<iostream>
using namespace std;

void sortArray(int* arr, int size) {
    if (size == 0 || size == 1) {
        return ;
    }

    for (int i=0; i<size-1; i++) {
        if (arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
    }

    sortArray(arr, size-1);
}

int main() {

    int arr[5] = {1,9,3,7,5};
    int size = 5;

    cout<<"Before sorting : ";
    for (int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    sortArray(arr, size);

    cout<<"After sorting : ";
    for (int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}