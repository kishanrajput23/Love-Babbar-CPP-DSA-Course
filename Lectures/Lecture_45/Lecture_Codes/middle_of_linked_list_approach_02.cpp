// this is approach 2

Node *findMiddle(Node *head) {
    // Write your code here
    if (head == NULL || head->next == NULL) {
        return head;
    }

    if (head->next->next == NULL) {
        return head->next;
    }


    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL) {
        fast = fast->next;

        if (fast != NULL) {
            fast = fast->next;
        }

        slow = slow->next;
    }

    return slow;
}

