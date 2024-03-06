#include<iostream>
using namespace std;

class stack {
    public:
    int top;
    int *arr;
    int size;

    stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if (size - top > 1) {
            top++;

            arr[top] = element;
        }
        else {
            cout<<"Stack overflow"<<endl;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        }
        else {
            cout<<"Stack underflow"<< endl;
        }
    }

    int peek() {
        if (top>=0) {
            return arr[top]; 
        }
        else {
            cout<<"Stack is empty"<<endl;
            return -1; 
        }
    }

    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {

    stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);

    cout<<"Peak element is : "<< st.peek()<<endl;

    st.pop();

    cout<<"Peak element is : "<< st.peek()<<endl;

    st.pop();

    cout<<"Peak element is : "<< st.peek()<<endl;

    st.pop();

    cout<<st.peek()<<endl;

    if (st.isEmpty()) {
        cout<<"Stack is empty."<<endl;
    }
    else {
        cout<<"Stack is not empty"<<endl;
    }

    return 0;
}