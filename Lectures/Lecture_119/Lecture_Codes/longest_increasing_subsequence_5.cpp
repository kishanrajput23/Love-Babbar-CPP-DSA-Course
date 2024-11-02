// Optimal solution [Binary Search With DP]

class Solution {
    public:
    int solve(int n, int a[]) {
        
        if (n == 0) {
            return 0;
        }
        
        vector<int> ans;
        ans.push_back(a[0]);
        
        for (int i=1; i<n; i++) {
            
            if (a[i] > ans.back()) {
                ans.push_back(a[i]);
            }
            
            int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[index] = a[i];
        }
        
        return ans.size();
    }
    
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]) {
       // your code here
       
       return solve(n, a);
    }
};