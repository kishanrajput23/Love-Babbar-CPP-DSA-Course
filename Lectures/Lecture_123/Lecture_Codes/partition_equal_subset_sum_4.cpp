// space optimization

class Solution {
  public:
    bool solve(int n, vector<int> &arr, int total) {
        vector<int> curr(total+1, 0);
        vector<int> next(total+1, 0);
        
        curr[0] = 1;
        next[0] = 1;
        
        for (int index=n-1; index>=0; index--) {
            for (int target=0; target<=total/2; target++) {
                bool include = 0;
                
                if (target-arr[index] >= 0) {
                    include = next[target-arr[index]];
                }
                
                bool exclude = next[target-0];
                
                curr[target] = include or exclude;
            }
            next = curr;
        }
        
        return next[total/2];
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