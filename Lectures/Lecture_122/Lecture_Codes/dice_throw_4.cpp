// Space Optimization

class Solution {
    public:
    long long solve(int d, int f, int t) {
        vector<long long> prev(t+1, 0);
        vector<long long> curr(t+1, 0);
        
        prev[0] = 1;
        
        for (int dice=1; dice<=d; dice++) {
            for (int target=1; target<=t; target++) {
                // calculating all possible ways for find target sum
                long long ans = 0;
                
                for (int i=1; i<=f; i++) {
                    if (target-i >= 0) {
                        ans += prev[target-i];
                    }
                }
                
                curr[target] = ans;
            }
            prev = curr;
        }
        
        return prev[t];
        
    }
        
    long long noOfWays(int m, int n, int x) {
        // code here
        return solve(n, m, x);
    }
};