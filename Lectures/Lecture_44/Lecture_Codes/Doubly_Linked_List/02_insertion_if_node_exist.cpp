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

// inserting at head
void insertAtHead(Node* &head, Node* &tail, int d) {
    // if linked list is empty
    if (head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// inserting at tail
void insertAtTail(Node* &head, Node* &tail, int d) {
    // if linked list is empty
    if (tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else {
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// inserting new node at given position
void insertAtPosition(Node* &head, Node* &tail, int position, int d) {
    // insert at start
    if (position == 1) {
        insertAtHead(head, tail, d);
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
        insertAtTail(head, tail, d);
        return;
    }

    // insert at given postion part 2
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

int main() {

    Node* node1 = new Node(10);     //dynamically creation of new node

    Node* head = node1;
    Node* tail = node1;

    print(head);
    cout<<"Doubly LL Length : "<<getLength(head)<<endl;

    insertAtHead(head, tail, 22);
    print(head);

    insertAtHead(head, tail, 41);
    print(head);

    insertAtTail(head, tail, 55);
    print(head);

    insertAtTail(head, tail, 99);
    print(head);

    insertAtPosition(head, tail, 1, 100);
    print(head);

    insertAtPosition(head, tail, 3, 60);
    print(head);

    insertAtPosition(head, tail, 8, 11);
    print(head);


    return 0;
}