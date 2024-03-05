/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/
// TC = O(NlogN)
// SC = O(logN)

node* findMid(node* head) {
    node* slow = head;
    node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* left, node* right) {
    if (left == NULL) {
        return right;
    }

    if (right == NULL) {
        return left;
    }

    node* ans = new node(-1);
    node* temp = ans;

    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}

node* mergeSort(node *head) {
    // Write your code here.

    if (head == NULL || head->next == NULL) {
        return head;
    }

    // step 1 : find mid of the linked list
    node* mid = findMid(head);

    // step 2 : dividing lists into two halves
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    // step 3 : sorting lists recursively
    left = mergeSort(left);
    right = mergeSort(right);

    // step 4 : merging lists
    node* result = merge(left, right);

    //  step 5 : return list 
    return result;
}
