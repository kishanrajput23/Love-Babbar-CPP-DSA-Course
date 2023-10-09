#include<iostream>
#include<deque>
using namespace std;

int main() {

    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_front(4);
    d.push_front(5);

    cout<<"The deque elements are : ";
    for (int i:d) {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"First Element : "<<d.front()<<endl;

    cout<<"Last Element : "<<d.back()<<endl;

    cout<<"Deque is empty or not : "<<d.empty()<<endl;

    d.pop_back();
    cout<<"After pop back elements are : ";
    for (int i:d) {
        cout<<i<<" ";
    }
    cout<<endl;

    d.pop_front();
    cout<<"After pop front elements are : ";
    for (int i:d) {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Before erase size of deque is : "<<d.size()<<endl;
    d.erase(d.begin(), d.begin()+1);
    cout<<"After erase size of deque is : "<<d.size()<<endl;
    
    return 0;
}