#include <bits/stdc++.h> 

void sortedInsert(stack<int>& s, int x) {
	if (s.empty() || (!s.empty() && s.top()<x)) {
		s.push(x);
		return ;
	}

	int num = s.top();
	s.pop();

	sortedInsert(s, x);

	s.push(num);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if (stack.empty()) {
		return;
	}

	int num = stack.top();
	stack.pop();

	// recursive call
	sortStack(stack);

	// function to insert numbers in sorted order
	sortedInsert(stack, num);
}