#include<bits/stdc++.h>

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

// TC = nk log(k)
// SC = O(k)

class Compare {
    public:
    bool operator() (Node* a, Node* b) {
        return a->data > b->data;
    }
};


Node* mergeKLists(vector<Node*> &listArray) {

    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Populate the priority queue with the heads of all lists
    for (Node* listHead : listArray) {
        if (listHead != NULL) {
            pq.push(listHead);
      }
    }

    // Create a dummy node to simplify the code
    Node* result = new Node(0);
    Node* ans = result;

    Node* temp;

    while (!pq.empty()) {
        temp = pq.top();
        pq.pop();
        
        ans->next = temp;
        ans = ans->next;

        if (temp->next != NULL) {
          pq.push(temp->next);
        }
    }

    return result->next;
}
