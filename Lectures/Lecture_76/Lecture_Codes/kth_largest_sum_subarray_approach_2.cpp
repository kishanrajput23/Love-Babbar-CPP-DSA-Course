#include<bits/stdc++.h>

// TC = n^2 log(n);
// SC = O(k)

int getKthLargest(vector<int> &arr, int k) {
	//	Write your code here.
	int n = arr.size();
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i=0; i<n; i++) {
		int sum = 0;
		for (int j=i; j<n; j++) {
			sum += arr[j];
			
			if (pq.size() < k) {
				pq.push(sum);
			}
			else {
				if (pq.top() < sum) {
					pq.pop();
					pq.push(sum);
				}
			}
		}
	}
	return pq.top();
}