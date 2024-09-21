// Recursion + Memoization

#include <bits/stdc++.h> 

int solve(vector<int> &num, int tar, vector<int> &dp) {
    if (tar < 0) {
        return 0;
    }

    if (tar == 0) {
        return 1;
    }

    if (dp[tar] != -1) {
        return dp[tar];
    }

    int sum = 0;
    for (int i=0; i<num.size(); i++) {
        sum += solve(num, tar-num[i], dp);
    }

    dp[tar] = sum;

    return dp[tar];
}

int findWays(vector<int> &num, int tar) {
    // Write your code here.
    vector<int> dp(tar+1, -1);

    return solve(num, tar, dp);
}