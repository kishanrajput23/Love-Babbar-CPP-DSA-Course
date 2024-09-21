// Recursion --> Gives TLE

#include <bits/stdc++.h> 

int solve(vector<int> &num, int tar) {
    if (tar < 0) {
        return 0;
    }

    if (tar == 0) {
        return 1;
    }

    int sum = 0;
    for (int i=0; i<num.size(); i++) {
        sum += solve(num, tar-num[i]);
    }

    return sum;
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    return solve(num, tar);
}