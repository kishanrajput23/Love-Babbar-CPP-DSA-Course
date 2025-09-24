// Simple O(n²) time, O(n) space - Corrected Implementation
class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();
        
        if (n <= 2) {
            return n;
        }
        
        int ans = 2;
        
        // Use rolling DP - only store DP for current ending position
        for (int i = 1; i < n; i++) {
            unordered_map<int, int> dp; // dp[diff] = max length ending at i with this diff
            
            for (int j = 0; j < i; j++) {
                int diff = arr[i] - arr[j];
                dp[diff] = 2; // At minimum: arr[j], arr[i]
                
                // Check if we can extend from any previous position
                for (int k = 0; k < j; k++) {
                    if (arr[j] - arr[k] == diff) {
                        dp[diff] = 3; // Found: arr[k], arr[j], arr[i]
                        
                        // Continue backwards to find full length
                        int curr = k;
                        int len = 3;
                        while (curr > 0) {
                            int target = arr[curr] - diff;
                            bool found = false;
                            for (int m = curr - 1; m >= 0; m--) {
                                if (arr[m] == target) {
                                    len++;
                                    curr = m;
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) break;
                        }
                        dp[diff] = len;
                        break;
                    }
                }
                
                ans = max(ans, dp[diff]);
            }
        }
        
        return ans;
    }
};
