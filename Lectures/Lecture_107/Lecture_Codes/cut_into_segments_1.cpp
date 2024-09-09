// Recursion --> Gives TLE

#include<bits/stdc++.h>

int solve(int n, int x, int y, int z) {
	if (n == 0) {
		return 0;
	}

	if (n < 0) {
		return INT_MIN;
	}

	int a = solve(n-x, x, y, z) + 1;
	int b = solve(n-y, x, y, z) + 1;
	int c = solve(n-z, x, y, z) + 1;

	return max(a, max(b, c));
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	int ans = solve(n, x, y, z);

	if (ans < 0) {
		return 0;
	}

	return ans;
}