// TC = O(N)
// SC = O(1)

class Solution
{
    public: 
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* temp = new Node(d);
        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    Node *copyList(Node *head)
    {
        //Write your code here
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        
        // step 1 : creating a clone of linked list
        while (temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }
        
        // step 2 : clone nodes add between original nodes
        Node* originalNodeList = head;
        Node* cloneNodeList = cloneHead;
        
        // setting up the links
        while (originalNodeList != NULL && cloneNodeList != NULL) {
            // changing links of original node list
            Node* next = originalNodeList->next;
            originalNodeList->next = cloneNodeList;
            originalNodeList = next;
            
            // changing links of clone node list
            next = cloneNodeList->next;
            cloneNodeList->next = originalNodeList;
            cloneNodeList = next;
        }
        
        // step 3 : copying random pointers
        temp = head;
        
        while (temp != NULL) {
            if (temp->next != NULL) {
                temp->next->arb = temp->arb ? temp->arb->next : temp->arb;
            }
            temp = temp->next->next;
        }
        
        // step 4 : revert changes done in step 2
        originalNodeList = head;
        cloneNodeList = cloneHead;
        
        while (originalNodeList != NULL && cloneNodeList != NULL) {\
            originalNodeList->next = cloneNodeList->next;
            originalNodeList = originalNodeList->next;
            
            if (originalNodeList != NULL) {
                cloneNodeList->next = originalNodeList->next;
            }
            cloneNodeList = cloneNodeList->next;
        }
        
        // step 5 : return ans
        return cloneHead;
        
    }
};