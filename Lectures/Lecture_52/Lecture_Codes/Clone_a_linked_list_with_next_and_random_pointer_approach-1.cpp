// TC = O(N)
// SC = O(N)

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
        
        // step 2 : creating map of nodes
        unordered_map<Node*, Node*> mp;
        
        Node* originalNodeList = head;
        Node* cloneNodeList = cloneHead;
        
        // setting up the mapping
        while (originalNodeList != NULL && cloneNodeList != NULL) {
            mp[originalNodeList] = cloneNodeList;
            originalNodeList = originalNodeList->next;
            cloneNodeList = cloneNodeList->next;
        }
        
        // step 3 : now setting up the random pointers
        originalNodeList = head;
        cloneNodeList = cloneHead;
        
        while (originalNodeList != NULL && cloneNodeList != NULL) {
            cloneNodeList->arb = mp[originalNodeList->arb];
            originalNodeList = originalNodeList->next;
            cloneNodeList = cloneNodeList->next;
        }
        
        return cloneHead;
        
    }
};