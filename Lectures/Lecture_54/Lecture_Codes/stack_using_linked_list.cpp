#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
        cout << "Element pushed: " << value << "\n";
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1; // Assuming -1 as an error code for an empty stack
        }

        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;

        cout << "Element popped: " << poppedValue << "\n";
        return poppedValue;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1; // Assuming -1 as an error code for an empty stack
        }

        return top->data;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void printStack() {
        Node* current = top;
        cout << "Stack: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    myStack.printStack();

    cout << "Top element: " << myStack.peek() << "\n";
    cout << "Stack size: " << myStack.getSize() << "\n";

    myStack.pop();
    myStack.printStack();

    return 0;
}
