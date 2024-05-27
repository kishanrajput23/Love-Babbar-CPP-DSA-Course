#include <bits/stdc++.h>

// function to find which heap is greater
int signum(int a, int b) {
	if (a == b) {
		return 0;
	}
	else if (a > b) {
		return 1;
	}
	else {
		return -1;
	}
}

void getMedian(int element, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, int &median) {

	switch (signum(maxi.size(), mini.size())) {
		case 0 : if (element > median) {
			mini.push(element);
			median = mini.top();
		}
		else {
			maxi.push(element);
			median = maxi.top();
		}
		break;

		case 1 : if (element > median) {
			mini.push(element);
			median = (mini.top() + maxi.top()) / 2;
		}
		else {
            // to maintain the max difference to 1 in b/w both heap
			mini.push(maxi.top());
			maxi.pop();

			maxi.push(element);
			median = (mini.top() + maxi.top()) / 2;
		}
		break;

		case -1 : if (element > median) {
            // to maintain the max difference to 1 in b/w both heap
			maxi.push(mini.top());
			mini.pop();

			mini.push(element);
			median = (mini.top() + maxi.top()) / 2;
		}
		else {
			maxi.push(element);
			median = (mini.top() + maxi.top()) / 2;
		}
		break;
	}
}

vector<int> findMedian(vector<int> &arr, int n){
	int median = 0;

	// Max heap for lower half of numbers
	priority_queue<int> maxheap;

	// Min heap for upper half of numbers
	priority_queue<int, vector<int>, greater<int>> minheap;

	vector<int> ans;

	for (int i=0; i<n; i++) {
		getMedian(arr[i], maxheap, minheap, median);
		ans.push_back(median);
	}

	return ans;
}
