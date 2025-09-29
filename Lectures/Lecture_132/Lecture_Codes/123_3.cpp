// Bottom Up DP
class Solution {
public:
    int solve(vector<int> &prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));;

        for (int index=n-1; index>=0; index--) {
            for (int buy=0; buy<=1; buy++) {
                for (int limit=1; limit<=2; limit++) {
                    int maxProfit = 0;

                    if (buy) {
                        int buy = -prices[index] + dp[index+1][0][limit];
                        int notBuy = 0 + dp[index+1][1][limit];
                        maxProfit = max(buy, notBuy);
                    }
                    else {
                        int sell = prices[index] + dp[index+1][1][limit-1];
                        int notSell = 0 + dp[index+1][0][limit];
                        maxProfit = max(sell, notSell);
                    }

                    dp[index][buy][limit] = maxProfit;
                }
            }
        }

        return dp[0][1][2];
    }

    int maxProfit(vector<int>& prices) {
        return solve(prices);
    }
};