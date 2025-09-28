// Alternative Bottom-Up DP with 2D vector for maxVal (Space Optimized)
// Time Complexity: O(n³)
// Space Complexity: O(n²)

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        
        // Precompute maximum values for all subarrays using 2D vector
        vector<vector<int>> maxVal(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) {
            maxVal[i][i] = arr[i];
            for (int j = i + 1; j < n; j++) {
                maxVal[i][j] = max(arr[j], maxVal[i][j-1]);
            }
        }
        
        // Bottom-up DP table
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Fill the DP table bottom-up
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                
                for (int k = i; k < j; k++) {
                    int cost = maxVal[i][k] * maxVal[k+1][j] + dp[i][k] + dp[k+1][j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        
        return dp[0][n-1];
    }
};