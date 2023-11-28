#include<iostream>
using namespace std;

void update(int **ptr) {
    // ptr = ptr+1;    ------> NO CHANGE

    // *ptr = *ptr+1;    ------> CHANGE OCCURS

    **ptr = **ptr+1;        // CHANGE OCCURS
}

int main() {

    int i = 5;
    int *p1 = &i;
    int **p2 = &p1;

    cout<<"Before updating values : "<<endl;
    cout<<"i : "<<i<<endl;
    cout<<"p1 : "<<p1<<endl;
    cout<<"p2 : "<<p2<<endl;

    update(p2);

    cout<<"After updating values : "<<endl;
    cout<<"i : "<<i<<endl;
    cout<<"p1 : "<<p1<<endl;
    cout<<"p2 : "<<p2<<endl;

    return 0;
}