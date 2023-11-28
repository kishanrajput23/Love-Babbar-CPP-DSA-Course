#include<iostream>
using namespace std;

// Below code genarates a warning as it is bad practice
// int& func(int n) {
//     int num = 10;
//     int& ans = num;
//     return ans;
// }

void update(int& n) {       // taking argument as a referencve variable
    n++;
}

int main() {

    int i = 5;

    // creating a reference variable
    int& j = i;

    cout<<i<<endl;
    i++;
    cout<<i<<endl;
    i++;
    cout<<i<<endl;
    cout<<j<<endl;

    int n = 5;
    cout<<"Before update : "<<n<<endl;

    update(n);

    cout<<"After update : "<<n<<endl;


    return 0;
}