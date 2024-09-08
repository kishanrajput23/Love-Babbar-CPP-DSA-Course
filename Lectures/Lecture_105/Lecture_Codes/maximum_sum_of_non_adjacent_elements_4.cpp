// space optimization

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

    // Variables to store the maximum sums
    int prev1 = nums[0];  // This is dp[i-2]
    
    int prev2 = max(nums[0], nums[1]);  // This is dp[i-1]
    
    // Iterate from the 2nd index to the end
    for (int i = 2; i < n; ++i) {
        int current = max(prev2, prev1 + nums[i]);  // Current max sum
        prev1 = prev2;  // Move prev2 to prev1
        prev2 = current;  // Update prev2 to current
    }
    
    return prev2;
}
