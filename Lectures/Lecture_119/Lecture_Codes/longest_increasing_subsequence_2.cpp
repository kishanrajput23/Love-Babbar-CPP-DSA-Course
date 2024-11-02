// Recursion + Memoization [TLE]

class Solution {
    public:
    int solve(int n, int a[], int currIndex, int prevIndex, vector<vector<int>> dp) {
        if (currIndex == n) {
            return 0;
        }
        
        if (dp[currIndex][prevIndex+1] != -1) {
            return dp[currIndex][prevIndex+1];
        }
        
        // include curr number
        int include = 0;
        if (prevIndex == -1 || a[currIndex] > a[prevIndex]) {
            include = 1 + solve(n , a, currIndex+1, currIndex, dp);
        }
        
        // exclude curr number
        int exclude = 0;
        exclude = 0 + solve(n, a, currIndex+1, prevIndex, dp);
        
        dp[currIndex][prevIndex+1] = max(include, exclude);
        
        return dp[currIndex][prevIndex+1];
    }
    
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]) {
       // your code here
       vector<vector<int>> dp(n, vector<int> (n+1, -1));
       
       return solve(n, a, 0, -1, dp);
    }
};