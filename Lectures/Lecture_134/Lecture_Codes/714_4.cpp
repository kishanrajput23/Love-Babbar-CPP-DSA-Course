// Space Optimized

class Solution {
public:
    int solve(vector<int> &prices, int fee) {
        int n = prices.size();

        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for (int index=n-1; index>=0; index--) {
            for (int buy=0; buy<=1; buy++) {
                int maxProfit = 0;

                if (buy) {
                    int buy = -prices[index] + next[0];
                    int notBuy = 0 + next[1];
                    maxProfit = max(buy, notBuy);
                }
                else {
                    int sell = prices[index] + next[1] - fee;
                    int notSell = 0 + next[0];
                    maxProfit = max(sell, notSell);
                }

                curr[buy] = maxProfit;
            }
            next = curr;
        }

        return next[1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        return solve(prices, fee);
    }
};