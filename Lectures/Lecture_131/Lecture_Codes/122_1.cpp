// Gives TLE

class Solution {
public:
    int solve(int index, int buy, vector<int> &prices) {
        if (index == prices.size()) {
            return 0;
        }

        int maxProfit = 0;

        if (buy) {
            int buy = -prices[index] + solve(index+1, 0, prices);
            int notBuy = 0 + solve(index+1, 1, prices);
            maxProfit += max(buy, notBuy);
        }
        else {
            int sell = prices[index] + solve(index+1, 1, prices);
            int notSell = 0 + solve(index+1, 0, prices);
            maxProfit += max(sell, notSell);
        }

        return maxProfit;
    }

    int maxProfit(vector<int>& prices) {
        return solve(0, 1, prices);
    }
};