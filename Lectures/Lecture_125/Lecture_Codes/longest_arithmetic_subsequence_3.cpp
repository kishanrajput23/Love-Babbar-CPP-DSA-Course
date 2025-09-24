// bottom-up DP

class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        if (n <= 2) {
            return n;
        }
        
        int ans = 0;
        
       unordered_map<int, int> dp[n+1];
        
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                int diff = arr[i] - arr[j];
                int cnt = 1;
                
                if (dp[j].count(diff)) {
                    cnt = dp[j][diff];
                }
                
                dp[i][diff] = 1 + cnt;
                ans = max(ans, dp[i][diff]);
            }
        }
        
        return ans;
    }
};
