void insertAtBottom(stack<int> &s, int x) {
    if (s.empty()) {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    insertAtBottom(s, x);

    s.push(num);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    if (stack.empty()) {
        return;
    }

    // before making next recusive call we store top element
    int num = stack.top();
    stack.pop();

    // recursive call
    reverseStack(stack);

    // insert at bottom function
    insertAtBottom(stack, num);
}