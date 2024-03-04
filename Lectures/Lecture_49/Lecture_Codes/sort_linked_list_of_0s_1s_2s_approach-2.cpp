/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

// TC => O(N);
// SC = O(1);

void inserAtTail(Node* &tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}

Node* sortList(Node *head){
    // Write your code here.

    // step 1 : create dummy pointers
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    // step 2 : creating 3 separate linked lists of 0s, 1s & 2s
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == 0) {
            inserAtTail(zeroTail, curr);
        }
        else if (curr->data == 1) {
            inserAtTail(oneTail, curr);
        }
        else if (curr->data == 2) {
            inserAtTail(twoTail, curr);
        }

        curr = curr->next;
    }

    // step 3 : merging 3 lists into one

    if (oneHead->next != NULL) {        // if 1s list is not empty
        zeroTail->next = oneHead->next;
    }
    else {      // if 1s list is empty
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // step 4 : setup the head
    head = zeroHead->next;

    // step 5 : deleting dummy nodes;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;

}