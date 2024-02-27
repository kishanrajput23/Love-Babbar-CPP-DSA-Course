#include <bits/stdc++.h>

// this is recursive approach

LinkedListNode<int> *reverse(LinkedListNode<int>* &head) {
    // base case
    if (head == NULL || head->next == NULL) {
        return head;
    }

    LinkedListNode<int> *newHead = reverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;

}


LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    return reverse(head);
}h