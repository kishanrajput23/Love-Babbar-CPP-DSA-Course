// TC = O(NKlog(K))
// SC = O(1);

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
Node* mergeTwoLists(Node* list1, Node* list2) {
        Node *dummy, *temp;
        dummy = new Node();
        temp = dummy;
        
        //when both list1 and list2 isn't empty
        while (list1 != NULL && list2 != NULL){
            if (list1->data < list2->data) {
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;   
            }
            temp = temp->next;
        }
        
        // we reached at the end of one of the list
        if (list1 != NULL) {
            temp->next = list1;
        }

        if (list2 != NULL) {
            temp->next = list2;
        }
        
        return dummy->next;
    }

    void mergeSort(vector<Node*>& listArray, int start, int end) {
        if (start >= end) {
            return ;
        }

        int mid = start + (end - start) / 2;

        // left part
        mergeSort(listArray, start, mid);

        // right part
        mergeSort(listArray, mid+1, end);

        // merging
        listArray[start] = mergeTwoLists(listArray[start], listArray[mid+1]);
    }

Node* mergeKLists(vector<Node*> &listArray) {
    if (listArray.size() == 0) {
            return NULL;
        }

        mergeSort(listArray, 0, listArray.size()-1);

        return listArray[0];
}
