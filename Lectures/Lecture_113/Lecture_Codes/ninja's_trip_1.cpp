// Recursion

#include<bits/stdc++.h>

int solve(int n, vector<int>&days, vector<int>&cost, int index) {
    // base case
    int x = days.size();
    if (index >= x) {
        return 0;
    }

    // 1 day pass
    int option1 = solve(n, days, cost, index+1) +cost[0];
    
    // 7 day pass
    int i;
    for (i=index; i<n && days[i]<days[index]+7; i++);
    int option2 = solve(n, days, cost, i) + cost[1];

    // 30 day pass
    for (i=index; i<n && days[i]<days[index]+30; i++);
    int option3 = solve(n, days, cost, i) +cost[2];

    int ans = min(option1, min(option2, option3) );
    return ans;
}

int minimumCoins(int n, vector<int> days, vector<int> cost) {
    // Write your code here.
    return solve(n, days, cost, 0);
}