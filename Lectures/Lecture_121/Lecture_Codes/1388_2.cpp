// Recursion + Memoization

class Solution {
public:
    int solve(int startIndex, int endIndex, vector<int>& slices, int n, vector<vector<int>> &dp) {
        if (n == 0 || startIndex > endIndex) {
            return 0;
        }

        if (dp[startIndex][n] != -1) {
            return dp[startIndex][n];
        }

        int take = slices[startIndex] + solve(startIndex+2, endIndex, slices, n-1, dp);

        int notTake = 0 + solve(startIndex+1, endIndex, slices, n, dp);

        dp[startIndex][n] = max(take, notTake);

        return dp[startIndex][n];
    }

    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();

        vector<vector<int>> dp1(k+1, vector<int>(k+1, -1));
        int case1 = solve(0, k-2, slices, k/3, dp1);

        vector<vector<int>> dp2(k+1, vector<int>(k+1, -1));
        int case2 = solve(1, k-1, slices, k/3, dp2);

        return max(case1, case2);
    }
};