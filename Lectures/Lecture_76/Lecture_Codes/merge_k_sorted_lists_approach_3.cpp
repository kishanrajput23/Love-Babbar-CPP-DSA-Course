/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// TC = O(NKlog(K))
// SC = O(1);

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy, *temp;
        dummy = new ListNode();
        temp = dummy;
        
        //when both list1 and list2 isn't empty
        while (list1 != NULL && list2 != NULL){
            if (list1->val < list2->val) {
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

    void mergeSort(vector<ListNode*>& lists, int start, int end) {
        if (start >= end) {
            return ;
        }

        int mid = start + (end - start) / 2;

        // left part
        mergeSort(lists, start, mid);

        // right part
        mergeSort(lists, mid+1, end);

        // merging
        lists[start] = mergeTwoLists(lists[start], lists[mid+1]);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }

        mergeSort(lists, 0, lists.size()-1);

        return lists[0];
    }
};