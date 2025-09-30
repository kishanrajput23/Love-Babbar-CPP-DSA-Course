// Gives TLE

class Solution {
public:
    int solve(int index, int buy, vector<int> &prices, int fee) {
        if (index == prices.size()) {
            return 0;
        }

        int maxProfit = 0;

        if (buy) {
            int buy = -prices[index] + solve(index+1, 0, prices, fee);
            int notBuy = 0 + solve(index+1, 1, prices, fee);
            maxProfit += max(buy, notBuy);
        }
        else {
            int sell = prices[index] + solve(index+1, 1, prices, fee) - fee;
            int notSell = 0 + solve(index+1, 0, prices, fee);
            maxProfit += max(sell, notSell);
        }

        return maxProfit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        return solve(0, 1, prices, fee);
    }
};