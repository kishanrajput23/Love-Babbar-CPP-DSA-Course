// this is approach 1

int getLength(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node *findMiddle(Node *head) {
    // Write your code here
    int length = getLength(head);
    int mid = length/2;
    int count = 0;
    while (count < mid) {
        head = head->next;
        count++;
    }
    return head;
}

