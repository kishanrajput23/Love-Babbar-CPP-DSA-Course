#include<iostream>
using namespace std;

void print(int arr[], int n, int start=0) {
    for (int i=start; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {

    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    print(arr, 10);
    print(arr, 10, 4);
    print(arr, 10, 7);

    return 0;
}