#include<bits/stdc++.h>
#include<stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> v;
    for (int i=0; i<n-1; i++) {
        bool found = false;
        for (int j=i+1; j<n; j++) {
            if (arr[i]>arr[j]) {
                v.push_back(arr[j]);
                found = true;
                break;
            }
        }
        if (!found) {
            v.push_back(-1);
        }
    }
    v.push_back(-1);
    return v;
}