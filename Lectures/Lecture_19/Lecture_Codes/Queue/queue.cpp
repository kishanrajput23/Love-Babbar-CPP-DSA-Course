#include<iostream>
#include<queue>
using namespace std;

int main() {

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<"First Element : "<<q.front()<<endl;

    cout<<"Last Element : "<<q.back()<<endl;

    cout<<"Queue is empty or not : "<<q.empty()<<endl;

    q.pop();
    cout<<"Front Element : "<<q.front()<<endl;

    return 0;
}