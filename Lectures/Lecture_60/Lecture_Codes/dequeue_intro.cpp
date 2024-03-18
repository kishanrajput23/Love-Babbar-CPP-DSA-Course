#include<iostream>
#include<deque>
using namespace std;

int main() {

    deque<int> q;

    q.push_front(20);
    q.push_back(30);

    cout<<q.front()<<" ";
    cout<<q.back()<<endl;

    q.pop_front();

    cout<<q.front()<<" ";
    cout<<q.back()<<endl;

    q.pop_back();

    if (q.empty()) {
        cout<<"queue is empty"<<endl;
    }
    else {
        cout<<"queue is not empty"<<endl;
    }

    return 0;
}