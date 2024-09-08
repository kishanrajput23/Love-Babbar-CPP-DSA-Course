// Recursion (from  n-1 to 0)
// Gives TLE

#include <bits/stdc++.h> 

int solve(vector<int> &nums, int n) {
    if (n < 0) {
        return 0;
    }

    if (n == 0) {
        return nums[0];
    }

    int include = solve(nums, n-2) + nums[n];
    int exclude = solve(nums, n-1) + 0;

    int ans = max(include, exclude);

    return ans;
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();

    int ans = solve(nums, n-1);

    return ans;
}