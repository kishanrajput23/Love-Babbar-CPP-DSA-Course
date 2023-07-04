#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	set<vector<int>> st;

   	sort(arr.begin(), arr.end());
	   
	for (int i=0; i<n-2; i++) {
		int left = i+1;
		int right = n-1;

		while (left < right) {
			int sum = arr[i] + arr[left] + arr[right];
			if (sum == K) {
				vector<int> temp = {arr[i], arr[left], arr[right]};
				sort(temp.begin(), temp.end());
				st.insert(temp);
				left++;
				right--;
			}
			else if (sum > K) {
				right--;
			}
			else {
				left++;
			}
		}
	}
	vector<vector<int>> ans(st.begin(), st.end());
   	return ans;
}