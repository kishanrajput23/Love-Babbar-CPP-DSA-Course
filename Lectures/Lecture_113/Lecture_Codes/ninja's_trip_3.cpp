// tabulation method

#include<bits/stdc++.h>

int solve(int n, vector<int> &days, vector<int> &cost) {
    // base case
    vector<int> dp(n+1, INT_MAX);

    dp[n] = 0;

    for (int k=n-1; k>=0; k--) {
        // 1 day pass
        int option1 = dp[k+1] + cost[0];
        
        // 7 day pass
        int i;
        for (i=k; i<n && days[i]<days[k]+7; i++);
        int option2 = dp[i] + cost[1];

        // 30 day pass
        for (i=k; i<n && days[i]<days[k]+30; i++);
        int option3 = dp[i] +cost[2];

        dp[k] = min(option1, min(option2, option3));
    }

    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost) {
    // Write your code here.

    return solve(n, days, cost);
}