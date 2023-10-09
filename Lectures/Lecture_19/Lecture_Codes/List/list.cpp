#include<iostream>
#include<list>
using namespace std;

int main() {

    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_front(4);
    l.push_front(5);

    cout<<"The list elements are : ";
    for (int i:l) {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"First Element : "<<l.front()<<endl;

    cout<<"Last Element : "<<l.back()<<endl;

    cout<<"Deque is empty or not : "<<l.empty()<<endl;

    l.pop_back();
    cout<<"After pop back elements are : ";
    for (int i:l) {
        cout<<i<<" ";
    }
    cout<<endl;

    l.pop_front();
    cout<<"After pop front elements are : ";
    for (int i:l) {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Before erase size of list is : "<<l.size()<<endl;
    l.erase(l.begin());
    cout<<"After erase size of list is : "<<l.size()<<endl;
  
    return 0;
}