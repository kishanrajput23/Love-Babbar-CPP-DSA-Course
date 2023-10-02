#include <bits/stdc++.h>

bool isPossible(const vector<int> &rank, int m, int mid) {
    int numOfDish = 0;
    int time = 0, R = 1;

    for (int cook = 0; cook < rank.size(); cook++) {
        while (time + R * rank[cook] <= mid) {
            if (numOfDish == m) {
                return true;
            }
            numOfDish++;
            time += R * rank[cook];
            R++;
        }
        time = 0;
        R = 1;
    }
    return numOfDish >= m; // Corrected condition
}

int minCookTime(const vector<int> &rank, int m) {
    int start = 0;
    int maxi = 0;

    for (int i = 1; i <= m; i++) {
        maxi = maxi + (i * rank[0]); // Use rank[0] instead of rank.back()
    }

    int end = maxi;
    int mid, ans = -1;

    while (start <= end) {
        mid = start + (end - start) / 2;
        if (isPossible(rank, m, mid)) {
            ans = mid;
            end = mid - 1;
        } 
        else {
            start = mid + 1;
        }
    }
    return ans;
}