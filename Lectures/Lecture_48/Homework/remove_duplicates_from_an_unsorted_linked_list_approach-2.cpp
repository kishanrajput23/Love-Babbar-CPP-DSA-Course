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

// This approach has some problems
// 1 -> Firstly it will sort the array and hence, it will given different output.
// 2 -> This approach will disturb the order of linked list and hence the test cases will not pass.
// Although, it will work fine, if order of linked list is not consider.
// T C = O(nlogn)
// S C  = O(1)

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort(Node* &head) {
    if (head == NULL || head->next == NULL) {
        return ;
    }

    bool swapped = true;
    Node* end = NULL;

    while (swapped) {
        swapped = false;
        Node* curr = head;

        while (curr->next != end) {
            if (curr->data > curr->next->data) {
                swap(curr, curr->next);
                swapped = true;
            }
            curr = curr->next;
        }
        end = curr;
    }
}
Node *removeDuplicates(Node *head)
{
    // Write your code here
    if (head == NULL || head->next == NULL) {
        return head;
    }

    bubbleSort(head);

    Node* curr = head;

    while (curr != NULL) {
        if ((curr->next != NULL) && curr->data == curr->next->data) {
            Node* nextNode = curr->next->next;
            Node* nodeToDelete = curr->next;
            delete(nodeToDelete);
            curr->next = nextNode;
        }
        else {
            curr = curr->next;
        }
    }
    return head;
}