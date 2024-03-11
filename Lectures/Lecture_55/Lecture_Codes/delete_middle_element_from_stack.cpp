#include <bits/stdc++.h> 

void solve(stack<int>&inputStack, int size, int count) {
   // base case
    if (count == size/2) {
        inputStack.pop();
        return ;
    }
    
    // before making next recusive call we store top element
    int num = inputStack.top();
    inputStack.pop();

    // recursive call
    solve(inputStack, size, count+1);

    // after going back from recursive call we push that top element to the stack
    inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
	
    // Write your code here
    int count = 0;
    solve(inputStack, N, count);
}