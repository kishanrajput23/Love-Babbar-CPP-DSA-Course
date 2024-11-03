// Tabulation Method

class Solution {
    public:
    long long solve(int d, int f, int t) {
        vector<vector<long long>> dp(d+1, vector<long long>(t+1, 0));
        
        dp[0][0] = 1;
        
        for (int dice=1; dice<=d; dice++) {
            for (int target=1; target<=t; target++) {
                // calculating all possible ways for find target sum
                long long ans = 0;
                
                for (int i=1; i<=f; i++) {
                    if (target-i >= 0) {
                        ans += dp[dice-1][target-i];
                    }
                }
                
                dp[dice][target] = ans;
            }
        }
        
        return dp[d][t];
        
    }
        
    long long noOfWays(int m, int n, int x) {
        // code here
        return solve(n, m, x);
    }
};