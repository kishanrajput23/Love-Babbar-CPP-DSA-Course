/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    // function to reverse linked list
    struct Node* reverse(struct Node* head) {
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
    // function to insert nodes at tail
    void insertAtTail(struct Node* &head, struct Node* &tail, int data) {
        Node* temp = new Node(data);
        
        // if list is already empty
        if (head == NULL) {
            head = temp;
            tail = temp;
            return ;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    
    struct Node* add(struct Node* first, struct Node* second) {
        int carry = 0;
        
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while (first != NULL && second != NULL) {
            int sum = carry + first->data + second->data;
            
            int digit = sum%10;
            
            // adding nodes to ans
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum / 10;
            
            first = first->next;
            second  = second->next;
            
        }
        
        while (first != NULL) {
            int sum = carry + first->data;
            int digit = sum%10;
            
            // adding nodes to ans
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum / 10;
            
            first = first->next;
        }
        
        while (second != NULL) {
            int sum = carry + second->data;
            int digit = sum%10;
            
            // adding nodes to ans
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum / 10;
            
            second = second->next;
        }
        
        while (carry != 0) {
            int sum = carry;
            int digit = sum%10;
            
            // adding nodes to ans
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum / 10;
        }
        
        return ansHead;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        // step 1 : reverse linked lists
        first = reverse(first);
        second = reverse(second);
        
        // step 2 : add two linked list;
        Node* ans = add(first, second);
        
        // step 3 : again reverse this linked list
        ans = reverse(ans);
        
        return ans;
    }
};