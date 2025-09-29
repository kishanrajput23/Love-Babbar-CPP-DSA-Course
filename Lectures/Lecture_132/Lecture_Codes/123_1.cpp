// Gives TLE

class Solution {
public:
    int solve(int index, int buy, vector<int> &prices, int limit) {
        if (index == prices.size()) {
            return 0;
        }

        if (limit == 0) {
            return 0;
        }

        int maxProfit = 0;

        if (buy) {
            int buy = -prices[index] + solve(index+1, 0, prices, limit);
            int notBuy = 0 + solve(index+1, 1, prices, limit);
            maxProfit = max(buy, notBuy);
        }
        else {
            int sell = prices[index] + solve(index+1, 1, prices, limit-1);
            int notSell = 0 + solve(index+1, 0, prices, limit);
            maxProfit = max(sell, notSell);
        }

        return maxProfit;
    }

    int maxProfit(vector<int>& prices) {
        return solve(0, 1, prices, 2);
    }
};