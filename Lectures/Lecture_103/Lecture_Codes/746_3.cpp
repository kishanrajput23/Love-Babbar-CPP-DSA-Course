class Solution {
public:
    // bottom-up
    int solve(vector<int> &cost, int n) {
        // step 1 : creation of dp array
        vector<int> dp(n+1);

        // step 2 : handle base case
        dp[0] = cost[0];
        dp[1] = cost[1];

        // step 3 : find rest of the solution
        for (int i=2; i<n; i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min(dp[n-1], dp[n-2]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int ans = solve(cost, n);

        return ans;
    }
};