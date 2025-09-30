// Recursion + Memoization

class Solution {
public:
    int solve(int index, int operations, int k, vector<int> &prices, vector<vector<int>> &dp) {
        if (index == prices.size()) {
            return 0;
        }

        if (operations == k*2) {
            return 0;
        }

        if (dp[index][operations] != -1) {
            return dp[index][operations];
        }

        int maxProfit = 0;

        if (operations % 2 == 0) {
            int buy = -prices[index] + solve(index+1, operations+1, k, prices, dp);
            int notBuy = 0 + solve(index+1, operations, k, prices, dp);
            maxProfit = max(buy, notBuy);
        }
        else {
            int sell = prices[index] + solve(index+1, operations+1, k, prices, dp);
            int notSell = 0 + solve(index+1, operations, k, prices, dp);
            maxProfit = max(sell, notSell);
        }

        return dp[index][operations] = maxProfit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2*k, -1));
        return solve(0, 0, k, prices, dp);
    }
};;