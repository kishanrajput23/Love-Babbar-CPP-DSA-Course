/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

// function to detect loop in linked list
Node* floysDetectLoop(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL) {
        fast = fast->next;

        if (fast != NULL) {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast) {
        return slow;
        }
    }
    return NULL; 
}

// function to find starting loop node in linked list
Node* getStartingNode(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* intersection = floysDetectLoop(head);

    if (intersection == NULL) {
        return NULL;
    }

    Node* slow = head;

    while (slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }

    
    return slow;
}

// function to remove loop in linked list
Node *removeLoop(Node *head)
{
    // Write your code here.

    Node* startingNode = getStartingNode(head);

    if (startingNode == NULL) {
        return head;
    }

    Node* temp = startingNode;

    while (temp->next != startingNode) {
        temp = temp->next;
    }

    temp->next = NULL;
    return head;
}