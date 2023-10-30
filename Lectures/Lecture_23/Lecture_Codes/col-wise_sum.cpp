#include<iostream>
using namespace std;

int main() {

    int arr[3][3];
    cout<<"Enter the elements : ";

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin>>arr[i][j];
        }
    }

    cout<<"Array elements are : "<<endl;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
    }

    int sum = 0;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            sum += arr[j][i];
        }
        cout<<"Col "<<i<<" Sum : "<<sum<<endl;
        sum = 0;
    }



    return 0;
}