#include<bits/stdc++.h>

// TC = n^2 log(n);
// SC = O(n^2)

int getKthLargest(vector<int> &arr, int k) {
	//	Write your code here.
	int n = arr.size();
	vector<int> sumStore;

	for (int i=0; i<n; i++) {
		int sum = 0;
		for (int j=i; j<n; j++) {
			sum += arr[j];
			sumStore.push_back(sum);
		}
	}

	sort(sumStore.begin(), sumStore.end());

	return sumStore[sumStore.size()-k];
}