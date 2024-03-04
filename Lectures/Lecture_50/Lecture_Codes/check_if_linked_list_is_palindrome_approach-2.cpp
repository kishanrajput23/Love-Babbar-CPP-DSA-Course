/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// TC = O(N);
// SC = O(1);

#include<bits/stdc++.h>

class Solution{
  public:
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
        
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode = NULL;
        
        while (curr != NULL) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
        
    }
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if (head == NULL || head->next == NULL) {
            return true;
        }
        
        // step 1 : find mid
        Node* mid = getMid(head);
        
        // step 2 : reverse second half after middle
        Node* temp = mid->next;
         mid->next = reverse(temp);
         
        //  step 3 : compare both halves
        Node* head1 = head;
        Node* head2 = mid->next;
        
        while (head2 != NULL) {
            if (head1->data != head2->data) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        
        // step 4 : make linked list like it was given in input (optional)
        temp = mid->next;
        mid->next = reverse(temp);
        
        return true;
    }
};