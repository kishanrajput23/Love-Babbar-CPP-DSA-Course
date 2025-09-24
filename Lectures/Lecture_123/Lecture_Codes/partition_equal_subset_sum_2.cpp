// Recursion + Memoization

class Solution {
  public:
    bool solve(int index, int n, vector<int> &arr, int target, vector<vector<int>> &dp) {
        if (index >= n) {
            return false;
        }
        
        if (target < 0) {
            return false;
        }
        
        if (target == 0) {
            return true;
        }
        
        if (dp[index][target] != -1) {
            return dp[index][target];
        }
        
        bool include = solve(index+1, n, arr, target-arr[index], dp);
        bool exclude = solve(index+1, n, arr, target-0, dp);
        
        return dp[index][target] = include or exclude;
    }
    
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int total = 0;
        
        for (auto i : arr) {
            total += i;
        }
        
        if (total % 2 != 0) {
            return false;
        }
        
        int target = total / 2;
        
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        
        return solve(0, n, arr, target, dp);
    }
};