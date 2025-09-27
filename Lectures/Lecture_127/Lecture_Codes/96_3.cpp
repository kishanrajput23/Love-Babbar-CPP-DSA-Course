// Bottom-Up DP (Tabulation)

class Solution {
public:
    int solve(int n) {
        vector<int> dp(n+1, 0);

        dp[0] = dp[1] = 1;

        // here i will be number of nodes
        for (int i=2; i<=n; i++) {
            // here j will be with current root node
            for (int j=1; j<=i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }

        return dp[n];
    }

    int numTrees(int n) {
        return solve(n);
    }
};