#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sorting(Node<int>* first, Node<int>* second) {
    // checking if first contains only 1 element
    if (first->next == NULL) {
        first->next = second;
        return first;
    }

    // creating pointers
    Node<int>* curr1 = first;
    Node<int>* nextNode1 = curr1->next;

    Node<int>* curr2 = second;
    Node<int>* nextNode2 = curr2->next;

    while (curr2 != NULL && nextNode1 != NULL) {
        if ((curr2->data <= nextNode1->data) && (curr2->data >= curr1->data)) {

            // adding node in between linked list
            curr1->next = curr2;
            nextNode2 = curr2->next;
            curr2->next = nextNode1;

            // moving pointers ahead
            curr1 = curr2;
            curr2 = nextNode2;
        }
        else {
            curr1 = nextNode1;
            nextNode1 = nextNode1->next;

            // if next node is null then directly connect to another list
            if (nextNode1 == NULL) {
              curr1->next = curr2;
              return first;
            }
        }
    }
    return first;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if (first == NULL) {
        return second;
    }

    if (second == NULL) {
        return first;
    }

    if (first->data <= second->data) {
        return sorting(first, second);

    }
    else {
        return sorting(second, first);
    }

    return first;
}
