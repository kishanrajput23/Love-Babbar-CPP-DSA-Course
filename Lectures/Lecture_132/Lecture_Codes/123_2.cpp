// Recursion + Memoization (Top-Down DP)

class Solution {
public:
    int solve(int index, int buy, vector<int> &prices, vector<vector<vector<int>>> &dp, int limit) {
        if (index == prices.size()) {
            return 0;
        }

        if (limit == 0) {
            return 0;
        }

        if (dp[index][buy][limit] != -1) {
            return dp[index][buy][limit];
        }

        int maxProfit = 0;

        if (buy) {
            int buy = -prices[index] + solve(index+1, 0, prices, dp, limit);
            int notBuy = 0 + solve(index+1, 1, prices, dp, limit);
            maxProfit = max(buy, notBuy);
        }
        else {
            int sell = prices[index] + solve(index+1, 1, prices, dp, limit-1);
            int notSell = 0 + solve(index+1, 0, prices, dp, limit);
            maxProfit = max(sell, notSell);
        }

        return dp[index][buy][limit] = maxProfit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, prices, dp, 2);
    }
};