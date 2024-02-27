#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;

        // memory free
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data : "<<value<<endl;
    }
};

void insertNode(Node* &tail, int element, int d) {
    // if empty list 
    if (tail == NULL) {
        Node* node1 = new Node(d);
        tail = node1;
        node1->next = node1;
    }
    else {
        // non empty list
        // assuming that element is present in the list
        Node* curr = tail;
        while(curr->data != element) {
            curr = curr->next;
        }

        // element found and it means current node representing found element
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail, int value) {
    if (tail == NULL) {
        cout<<"List is empty"<<endl;
        return ;
    }
    else {
        // assuming that the given value present in the linked list
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // if 1 node only there in linked list
        if (curr == prev) {
            tail = NULL;
        } 

        // if >=2 only node there in linked list
        else if (tail == curr) {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;

    }
}

void print(Node* tail) {
    Node* temp = tail;

    // empty list
    if (tail == NULL) {
        cout<<"List is empty"<<endl;
        return;
    }

    do {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail != temp);

    cout<<endl;
}

bool isCircularLinkedList(Node* tail) {
    if (tail == NULL) {
        return true;
    }

    Node* temp = tail->next;

    while (temp != NULL && temp != tail) {
        tail = tail->next;
    }

    if (temp == tail) {
        return true;
    }

    return false;
} 

int main() {

    Node* tail = NULL;

    // inserting in empty list
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    insertNode(tail, 9, 10);
    print(tail);

    deleteNode(tail, 3);
    print(tail);

    deleteNode(tail, 5);
    print(tail);

    if (isCircularLinkedList(tail)) {
        cout<<"Linked list is circular."<<endl;
    }
    else {
        cout<<"Linked list is not a circular."<<endl;
    }

    return 0;
}