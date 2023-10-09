#include<iostream>
#include<vector>
using namespace std;

int main() {

    vector<int> a(5, 1);    //this will create a vector of size 5 and intialize all elements with 1

    vector<int> n(a);   // this will copy the all elements of vector a into n

    vector<int> v;  // we create vector like this if we don't know the size
    cout<<"capacity : "<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"capacity : "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"capacity : "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"capacity : "<<v.capacity()<<endl;  
    cout<<"size : "<<v.size()<<endl;   
    
    cout<<"Element at index 2 : "<<v.at(2)<<endl;

    cout<<"First Element : "<<v.front()<<endl;

    cout<<"Last Element : "<<v.back()<<endl;

    cout<<"Before pop elements are : ";
    for (int i:v) {
        cout<<i<<" ";
    }
    cout<<endl;

    v.pop_back();

    cout<<"After pop elements are : ";
    for (int i:v) {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Before clear size and capacity of vector are : "<<v.size()<<" and "<<v.capacity()<<endl;
    v.clear();  // the capacity will remain 4
    cout<<"After clear size and capacity of vector are : "<<v.size()<<" and "<<v.capacity()<<endl;
    return 0;
}