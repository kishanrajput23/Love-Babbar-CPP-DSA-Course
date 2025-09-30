// Bottom Up DP

class Solution {
public:
    int solve(int k, vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

        for (int index=n-1; index>=0; index--) {
            for (int operations=0; operations<2*k; operations++) {
                int maxProfit = 0;

                if (operations % 2 == 0) {
                    int buy = -prices[index] + dp[index+1][operations+1];
                    int notBuy = 0 + dp[index+1][operations];
                    maxProfit = max(buy, notBuy);
                }
                else {
                    int sell = prices[index] + dp[index+1][operations+1];
                    int notSell = 0 + dp[index+1][operations];
                    maxProfit = max(sell, notSell);
                }

                dp[index][operations] = maxProfit;
            }
        }
        return dp[0][0];
    }

    int maxProfit(int k, vector<int>& prices) {
        return solve(k, prices);
    }
};