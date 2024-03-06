#include<iostream>
#include<stack>

using namespace std;

int main() {

    stack<int> s;

    s.push(2);
    s.push(5);
    s.push(7);
    s.push(9);

    cout<<"Size of stack is : "<<s.size()<<endl;

    s.pop();
    s.pop();

    cout<<"Size of stack is : "<<s.size()<<endl;

    cout<<"Top element in satck is : "<<s.top()<<endl;

    if (s.empty()) {
        cout<<"Stack is empty."<<endl;
    }
    else {
        cout<<"Stack is not empty"<<endl;
    }

    return 0;
}