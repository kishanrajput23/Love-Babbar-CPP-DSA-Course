// space optimisation

#include <bits/stdc++.h> 

int solve(vector<int> &weight, vector<int> &value, int n, int capacity) {

	vector<int> prev(capacity+1, 0);
	vector<int> curr(capacity+1, 0);

	for (int w=weight[0]; w<=capacity; w++) {
		if (weight[0] <= capacity) {
			prev[w] = value[0];
		}
		else {
			prev[w] = 0;
		}
	}

	for (int index=1; index<n; index++) {
		for (int w=0; w<=capacity; w++) {
			int include = 0;

			if (weight[index] <= w) {
				include = value[index] + prev[w-weight[index]];
			}

			int exclude = 0 + prev[w];

			curr[w] = max(include, exclude);
		}

		prev = curr;
	}

	return prev[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)  {
	// Write your code here

	return solve(weight, value, n, maxWeight);
}