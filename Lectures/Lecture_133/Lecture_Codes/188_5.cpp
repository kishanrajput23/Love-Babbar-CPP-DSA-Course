// Space Optimization

class Solution {
public:
    int solve(int k, vector<int> &prices) {
        int n = prices.size();

        vector<int> curr(2*k+1, 0);
        vector<int> next(2*k+1, 0);

        for (int index=n-1; index>=0; index--) {
            for (int operations=0; operations<2*k; operations++) {
                int maxProfit = 0;

                if (operations % 2 == 0) {
                    int buy = -prices[index] + next[operations+1];
                    int notBuy = 0 + next[operations];
                    maxProfit = max(buy, notBuy);
                }
                else {
                    int sell = prices[index] + next[operations+1];
                    int notSell = 0 + next[operations];
                    maxProfit = max(sell, notSell);
                }

                curr[operations] = maxProfit;
            }
            next = curr;
        }
        return next[0];
    }

    int maxProfit(int k, vector<int>& prices) {
        return solve(k, prices);
    }
};