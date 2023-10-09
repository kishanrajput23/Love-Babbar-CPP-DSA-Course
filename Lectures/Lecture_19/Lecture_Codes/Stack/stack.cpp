#include<iostream>
#include<stack>
using namespace std;

int main() {

    stack<string> s;

    s.push("Kishan");
    s.push("Kumar");
    s.push("Rai");
    
    cout<<"Top element : "<<s.top()<<endl;

    s.pop();
    cout<<"Top element : "<<s.top()<<endl;

    s.pop();
    cout<<"Top element : "<<s.top()<<endl;

    cout<<"Size of stack : "<<s.size()<<endl;
    return 0;
}