// Recursion [TLE]

class Solution {
    public:
    int solve(int n, int a[], int currIndex, int prevIndex) {
        if (currIndex == n) {
            return 0;
        }
        
        // include curr number
        int include = 0;
        if (prevIndex == -1 || a[currIndex] > a[prevIndex]) {
            include = 1 + solve(n , a, currIndex+1, currIndex);
        }
        
        // exclude curr number
        int exclude = 0;
        exclude = 0 + solve(n, a, currIndex+1, prevIndex);
        
        return max(include, exclude);
    }
    
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]) {
       // your code here
       return solve(n, a, 0, -1);
    }
};