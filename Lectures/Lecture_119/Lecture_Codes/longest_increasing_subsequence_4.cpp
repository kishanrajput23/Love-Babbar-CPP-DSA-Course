// Space Optimization [TLE]

class Solution {
    public:
    int solve(int n, int a[]) {
        
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for (int currIndex = n-1; currIndex >= 0; currIndex--) {
            for (int prevIndex = currIndex-1; prevIndex >= -1; prevIndex--) {
                
                // include curr number
                int include = 0;
                if (prevIndex == -1 || a[currIndex] > a[prevIndex]) {
                    include = 1 + nextRow[currIndex+1];
                }
                
                // exclude curr number
                int exclude = 0 + nextRow[prevIndex+1];
                
                currRow[prevIndex+1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        
        return nextRow[0];
    }
    
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]) {
       // your code here
       
       return solve(n, a);
    }
};