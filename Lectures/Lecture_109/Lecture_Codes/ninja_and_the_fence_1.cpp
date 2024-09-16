// Recursion --> Gives TLE

#include <bits/stdc++.h> 

#define MOD 1000000007

int add(int a, int b) {
    return ((a%MOD) + (b%MOD)) % MOD;
}

int mul(int a, int b) {
    return ((a%MOD) * (b%MOD)) % MOD;
}

int solve (int n, int k) {
    if (n == 1) {
        return k;
    }

    if (n == 2) {
        return add(k, mul(k, k-1));
    }

    // int ans = [solve(n-2) * (k-1)] + [solve(n-1) * (k-1)]
    int ans = add(mul(solve(n-2, k), k-1), mul(solve(n-1, k), k-1));

    return ans;
}

int numberOfWays(int n, int k) {
    // Write your code here.
    return solve(n, k);
}
