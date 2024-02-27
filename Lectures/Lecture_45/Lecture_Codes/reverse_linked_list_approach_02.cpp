#include <bits/stdc++.h>

// this is recursive approach

void reverse(LinkedListNode<int>* &head, LinkedListNode<int> *prev, LinkedListNode<int> *curr) {
    // base case
    if (curr == NULL) {
        head = prev;
        return;
    }
    LinkedListNode<int> *forward = curr->next;

    reverse(head, curr, forward);
    curr->next = prev;

}


LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    reverse(head, prev, curr);
    return head;
}