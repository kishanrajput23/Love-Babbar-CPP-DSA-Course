// Recursion + Memoization

class Solution {
    public:
    long long solve(int dice, int faces, int target, vector<vector<long long>> &dp) {
        // base cases
        if (target < 0) {
            return 0;
        }
        
        if (dice == 0 && target != 0) {
            return 0;
        }
        
        if (target == 0 && dice != 0) {
            return 0;
        }
        
        if (dice == 0 && target == 0) {
            return 1;
        }
        
        if (dp[dice][target] != -1) {
            return dp[dice][target];
        }
        
        // calculating all possible ways for find target sum
        long long ans = 0;
        
        for (int i=1; i<=faces; i++) {
            ans += solve(dice-1, faces, target-i, dp);
        }
        
        return dp[dice][target] = ans;
        
    }
        
    long long noOfWays(int m, int n, int x) {
        // code here
        vector<vector<long long>> dp(n+1, vector<long long>(x+1, -1));
        return solve(n, m, x, dp);
    }
};