#include <bits/stdc++.h> 

void solve(stack<int>& myStack, int x) {
    // base case;
    if (myStack.empty()) {
        myStack.push(x);
        return;
    }

    // before making next recusive call we store top element
    int num = myStack.top();
    myStack.pop();

    // recursive call
    solve(myStack, x);

    // after going back from recursive call we push that top element to the stack
    myStack.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack, x);
    return myStack;
}
