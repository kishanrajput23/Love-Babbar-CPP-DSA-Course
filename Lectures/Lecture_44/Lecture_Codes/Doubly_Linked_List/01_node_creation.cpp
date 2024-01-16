#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

// traversing on linked list
void print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next; 
    }
    cout<<endl;
}

// gives length of linked list
int getLength(Node* head) {
    Node* temp = head;
    int length = 0;

    while(temp != NULL) {
        length++;
        temp = temp->next; 
    }
    return length;
}

int main() {

    Node* node1 = new Node(10);     //dynamically creation of new node

    Node* head = node1;
    Node* tail = node1;

    print(head);
    cout<<"Doubly LL Length : "<<getLength(head)<<endl;

    return 0;
}