// Bottom Up DP

class Solution {
public:
    int solve(vector<int> &prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for (int index=n-1; index>=0; index--) {
            for (int buy=0; buy<=1; buy++) {
                int maxProfit = 0;

                if (buy) {
                    int buy = -prices[index] + dp[index+1][0];
                    int notBuy = 0 + dp[index+1][1];
                    maxProfit = max(buy, notBuy);
                }
                else {
                    int sell = prices[index] + dp[index+1][1] - fee;
                    int notSell = 0 + dp[index+1][0];
                    maxProfit = max(sell, notSell);
                }

                dp[index][buy] = maxProfit;
            }
        }

        return dp[0][1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        return solve(prices, fee);
    }
};