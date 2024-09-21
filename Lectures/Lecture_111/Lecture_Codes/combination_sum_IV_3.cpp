// tabulation method

#include <bits/stdc++.h> 

int solve(vector<int> &num, int tar) {
    vector<int> dp(tar+1, 0);

    dp[0] = 1;

    for (int i=1; i<=tar; i++) {
        for (int j=0; j<num.size(); j++) {
            if (i - num[j] >= 0) {
                dp[i] += dp[i - num[j]];
            }
        }
    }

    return dp[tar];
}

int findWays(vector<int> &num, int tar) {

    return solve(num, tar);
}