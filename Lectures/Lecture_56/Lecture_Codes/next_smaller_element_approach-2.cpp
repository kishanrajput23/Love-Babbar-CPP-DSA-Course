#include<bits/stdc++.h>
#include<stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> v(n);
    stack<int> s;
    s.push(-1);

    for (int i=n-1; i>=0; i--) {
        int curr = arr[i];
        while (s.top() >= arr[i]) {
            s.pop();
        }
        v[i] = s.top();
        s.push(curr);
    }
    return v;
}