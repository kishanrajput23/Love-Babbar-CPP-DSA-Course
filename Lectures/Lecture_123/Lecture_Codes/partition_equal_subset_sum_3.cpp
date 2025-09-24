// tabulation method

class Solution {
  public:
    bool solve(int n, vector<int> &arr, int total) {
        
        vector<vector<int>> dp(n+1, vector<int>(total+1, 0));
        
        for (int i=0; i<=n; i++) {
            dp[i][0] = 1;
        }
        
        for (int index=n-1; index>=0; index--) {
            for (int target=0; target<=total/2; target++) {
                bool include = 0;
                
                if (target-arr[index] >= 0) {
                    include = dp[index+1][target-arr[index]];
                }
                
                bool exclude = dp[index+1][target-0];
                
                dp[index][target] = include or exclude;
            }
        }
        
        return dp[0][total/2];
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
        
        return solve(n, arr, total);
    }
};