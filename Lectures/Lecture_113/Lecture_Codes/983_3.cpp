// tabulation method

class Solution {
public:
    int solve(int n, vector<int> &days, vector<int> &costs) {
        vector<int> dp(n+1, INT_MAX);

        dp[n] = 0;

        for (int k=n-1; k>=0; k--) {
            // 1 day pass
            int option1 = dp[k+1] + costs[0];
            
            // 7 day pass
            int i;
            for (i=k; i<n && days[i]<days[k]+7; i++);
            int option2 = dp[i] + costs[1];

            // 30 day pass
            for (i=k; i<n && days[i]<days[k]+30; i++);
            int option3 = dp[i] +costs[2];

            dp[k] = min(option1, min(option2, option3));
        }

        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        return solve(n, days, costs);
    }
};