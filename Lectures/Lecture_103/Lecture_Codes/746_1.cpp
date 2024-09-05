// simple recursive solution

class Solution {
public:
    int solve(vector<int> &cost, int n) {
        if (n == 0) {
            return cost[0];
        }

        if (n == 1) {
            return cost[1];
        }

        int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));

        return ans;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int ans = min(solve(cost, n-1), solve(cost, n-2));

        return ans;
    }
};