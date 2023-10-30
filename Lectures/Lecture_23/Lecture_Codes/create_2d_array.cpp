#include<iostream>
using namespace std;

int main() {

    // ways to create 2D array
    // int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    // int arr[3][4] = {{1,11,111,1111}, {2,22,222,2222}, {3,33,333,3333}};

    // creating a 2D array
    int arr1[3][3];

    // taking input in 2D array
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin>>arr1[i][j];
        }
    }

    // printing 2D array
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cout<<arr1[i][j] << " ";
        }
        cout<<endl;
    }


    // column wise input and printing in 2D array

    int arr2[3][4];

    // taking input in 2D array
    for (int i=0; i<4; i++) {
        for (int j=0; j<3; j++) {
            cin>>arr2[j][i];
        }
    }

    // printing 2D array
    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++) {
            cout<<arr2[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}