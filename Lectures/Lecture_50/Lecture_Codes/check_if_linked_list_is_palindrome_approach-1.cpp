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
// SC = O(N);

#include<bits/stdc++.h>

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        vector<int> v;
        
        Node* temp = head;
        while (temp != NULL) {
            v.push_back(temp->data);
            temp = temp->next;
        }
        
        int i=0;
        int j = v.size()-1;
        
        while (i <= j) {
            if (v[i] != v[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
};