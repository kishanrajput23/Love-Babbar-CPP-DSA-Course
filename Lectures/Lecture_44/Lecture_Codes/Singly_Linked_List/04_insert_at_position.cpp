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
};

// inserting new node at head or starting
void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

// inserting new node at tail or ending
void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

// inserting new node at given position
void insertAtPosition(Node* &head, Node* &tail, int position, int d) {
    // insert at start
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    // insert at given postion part 1
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    // insert at last
    if (temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }

    // insert at given postion part 2
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// print the linked list
void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next; 
    }
    cout<<endl;
}

int main() {

    // new node creation
    Node* node1 = new Node(10);     
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;

    // head pointed to node1
    Node* head = node1;

    // tail pointed to node1
    Node* tail = node1;
    print(tail);

    insertAtTail(tail, 12);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(head, tail, 3, 22);
    print(head);

    insertAtPosition(head, tail, 1, 99);
    print(head);

    insertAtPosition(head, tail, 6, 100);
    print(head);

    // verify head and tail
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    return 0;
}