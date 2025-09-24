// brute force

class Solution {
  public:
    
    int solve(int index, int diff, vector<int> &arr) {
        if (index < 0) {
            return 0;
        }
        
        int ans = 0;
        
        for (int i=index-1; i>=0; i--) {
            if (arr[index] - arr[i] == diff) {
                ans = max(ans, 1+solve(i, diff, arr));
            }
        }
        
        return ans;
    }
    
    int lengthOfLongestAP(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        if (n <= 2) {
            return n;
        }
        
        int ans = 0;
        
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                ans = max(ans, 2+solve(i, arr[j] - arr[i], arr));
            }
        }
        
        return ans;
    }
};