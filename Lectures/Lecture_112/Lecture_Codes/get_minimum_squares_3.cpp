// tabulation method

class Solution {
    public:
    
    int solve(int n) {
        vector<int> dp(n+1, INT_MAX); 
        
        dp[0] = 0;
        
        for (int i=1; i<=n; i++) {
            for (int j=1; j*j<=n; j++) {
                if (i - j*j >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - j*j]);
                }
            }
        }
        
        return dp[n];
    }
    
    int MinSquares(int n) {
        // Code here
        
        return solve(n);
    }
};