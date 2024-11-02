// Tabulation Method [TLE]

class Solution {
    public:
    int solve(int n, int a[]) {
        
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for (int currIndex = n-1; currIndex >= 0; currIndex--) {
            for (int prevIndex = currIndex-1; prevIndex >= -1; prevIndex--) {
                
                // include curr number
                int include = 0;
                if (prevIndex == -1 || a[currIndex] > a[prevIndex]) {
                    include = 1 + dp[currIndex+1][currIndex+1];
                }
                
                // exclude curr number
                int exclude = 0 + dp[currIndex+1][prevIndex+1];
                
                dp[currIndex][prevIndex+1] = max(include, exclude);
            }
        }
        
        return dp[0][0];
    }
    
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]) {
       // your code here
       
       return solve(n, a);
    }
};