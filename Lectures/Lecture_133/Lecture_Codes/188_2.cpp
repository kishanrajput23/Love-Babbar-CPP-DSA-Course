// Recursion (By using transection/operations method)
// Probably gives TLE

class Solution {
public:
    int solve(int index, int operations, int k, vector<int> &prices) {
        if (index == prices.size()) {
            return 0;
        }

        if (operations == k*2) {
            return 0;
        }

        int maxProfit = 0;

        if (operations % 2 == 0) {
            int buy = -prices[index] + solve(index+1, operations+1, k, prices);
            int notBuy = 0 + solve(index+1, operations, k, prices);
            maxProfit = max(buy, notBuy);
        }
        else {
            int sell = prices[index] + solve(index+1, operations+1, k, prices);
            int notSell = 0 + solve(index+1, operations, k, prices);
            maxProfit = max(sell, notSell);
        }

        return maxProfit;
    }

    int maxProfit(int k, vector<int>& prices) {
        return solve(0, 0, k, prices);
    }
};;