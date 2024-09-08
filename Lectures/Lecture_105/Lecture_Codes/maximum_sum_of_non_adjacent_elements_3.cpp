// Tabulation menthod

#include <bits/stdc++.h> 

using namespace std;

int maximumNonAdjacentSum(vector<int> &nums) {
    int n = nums.size();
    
    // Edge cases
    if (n == 0) {
      return 0;
    }

    if (n == 1) {
      return nums[0];
    }

    // Create a dp array to store the maximum sum at each index
    vector<int> dp(n);
    
    // Base cases
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    
    // Fill the dp array
    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    
    // The last element in dp array will have the answer
    return dp[n-1];
}
