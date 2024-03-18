#include<iostream>
#include<queue>

using namespace std;

int main() {

    queue<int> q;

    q.push(11);
    q.push(13);
    q.push(15);
    q.push(17);

    cout<<"front of the queue is : "<<q.front()<<endl;

    cout<<"size of the queue is : "<<q.size()<<endl;

    q.pop();
    q.pop();

    cout<<"size of the queue is : "<<q.size()<<endl;

    cout<<"front of the queue is : "<<q.front()<<endl;

    cout<<"rear of the queue is : "<<q.back()<<endl;

    if (q.empty()) {
        cout<<"queue is empty"<<endl;
    }
    else {
        cout<<"queue is not empty"<<endl;
    }

    return 0;
}