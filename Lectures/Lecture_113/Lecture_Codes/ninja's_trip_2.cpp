// Recursion + Memoization

#include<bits/stdc++.h>

int solve(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp) {
    // base case
    int x = days.size();
    if (index >= x) {
        return 0;
    }

    if (dp[index] != -1) {
        return dp[index];
    }

    // 1 day pass
    int option1 = solve(n, days, cost, index+1, dp) +cost[0];
    
    // 7 day pass
    int i;
    for (i=index; i<n && days[i]<days[index]+7; i++);
    int option2 = solve(n, days, cost, i, dp) + cost[1];

    // 30 day pass
    for (i=index; i<n && days[i]<days[index]+30; i++);
    int option3 = solve(n, days, cost, i, dp) +cost[2];

    dp[index] = min(option1, min(option2, option3));

    return dp[index];
}

int minimumCoins(int n, vector<int> days, vector<int> cost) {
    // Write your code here.
    vector<int> dp(n+1, -1);

    return solve(n, days, cost, 0, dp);
}