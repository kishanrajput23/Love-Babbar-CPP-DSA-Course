#include <bits/stdc++.h> 
void reverseArray(vector<int> &arr , int m)
{
	// Write your code here.
	int s = m+1;
	int e = arr.size()-1;

	while (s<=e) {
		swap(arr[s], arr[e]);
		s++;
		e--;
	}
}
