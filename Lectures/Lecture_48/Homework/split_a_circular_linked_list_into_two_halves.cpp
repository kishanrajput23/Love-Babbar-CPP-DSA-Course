void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    if (head == NULL) {
        return ;
    }
    
    Node* slow = head;
    Node* fast = head->next;
    
    while (fast != head && fast->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    *head1_ref = head;      // points to head1
    *head2_ref = slow->next;        // points to head 2
    slow->next = *head1_ref;        // made first circular liat
    
    Node* curr = *head2_ref;
    
    while (curr->next != head) {
        curr = curr->next;
    }
    
    curr->next = *head2_ref;   
}