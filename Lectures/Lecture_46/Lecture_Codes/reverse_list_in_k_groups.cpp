Node* kReverse(Node* head, int k) {
    // Write your code here.

    Node* temp = head;
    int len=0;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    // Base Case
    if(len<k || len==0){
      return head;
    }

    // step 1 : reverse in k group
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = NULL;
    int count = 0;

    while (curr != NULL && count < k) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        count++;

    }

    // step 2 : recursion
    if (nextNode != NULL) {
        head->next = kReverse(nextNode, k);
    }

    // step 3 : return head of reverse list
    return prev;
}