// more space optimisation

#include <bits/stdc++.h> 

int solve(vector<int> &weight, vector<int> &value, int n, int capacity) {

	vector<int> curr(capacity+1, 0);

	for (int w=weight[0]; w<=capacity; w++) {
		if (weight[0] <= capacity) {
			curr[w] = value[0];
		}
		else {
			curr[w] = 0;
		}
	}

	for (int index=1; index<n; index++) {
		for (int w=capacity; w>=0; w--) {
			int include = 0;

			if (weight[index] <= w) {
				include = value[index] + curr[w-weight[index]];
			}

			int exclude = 0 + curr[w];

			curr[w] = max(include, exclude);
		}
	}

	return curr[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)  {
	// Write your code here

	return solve(weight, value, n, maxWeight);
}