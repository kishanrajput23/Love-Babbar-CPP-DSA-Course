// Recursion + Memoization (Top-Down DP)

class Solution {
public:
    int solve(int index, int buy, vector<int> &prices, int fee, vector<vector<int>> &dp) {
        if (index == prices.size()) {
            return 0;
        }

        if (dp[index][buy] != -1) {
            return dp[index][buy];
        }

        int maxProfit = 0;

        if (buy) {
            int buy = -prices[index] + solve(index+1, 0, prices, fee, dp);
            int notBuy = 0 + solve(index+1, 1, prices, fee, dp);
            maxProfit = max(buy, notBuy);
        }
        else {
            int sell = prices[index] + solve(index+1, 1, prices, fee, dp) - fee;
            int notSell = 0 + solve(index+1, 0, prices, fee, dp);
            maxProfit = max(sell, notSell);
        }

        return dp[index][buy] = maxProfit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, fee, dp);
    }
};