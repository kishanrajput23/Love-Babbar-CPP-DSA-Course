#include<iostream>
using namespace std;

bool isPresent(int arr[][4], int target, int row, int col) {
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (arr[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}

int main() {

    int target;
    int arr[3][4];
    cout<<"Enter the elements : ";

    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++) {
            cin>>arr[i][j];
        }
    }

    cout<<"Enter the element you want to search : ";
    cin>>target;

    if (isPresent(arr, target, 3, 4)) {
        cout<<"Elememt Found!!"<<endl;
    }
    else {
        cout<<"Element Not Found!!"<<endl;
    }


    return 0;
}