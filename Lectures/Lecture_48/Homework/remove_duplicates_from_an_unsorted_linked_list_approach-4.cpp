#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

// T C = O(N)
// S C = O(N)

Node *removeDuplicates(Node *head)
{
    // Write your code here
    Node* curr = head;
    unordered_set<int> seen;

    if (curr == NULL) {
        return head;
    }
    else {
        seen.insert(curr->data);
    }

    while (curr != NULL && curr->next != NULL) {
        if (seen.find(curr->next->data) != seen.end()) {
            // same elements
            curr->next = curr->next->next;
        }
        else {
            seen.insert(curr->next->data);
            curr = curr->next;
        }
    }
    return head;
}