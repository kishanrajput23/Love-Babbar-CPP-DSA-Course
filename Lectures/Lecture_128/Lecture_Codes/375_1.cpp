// Gives TLE

class Solution {
public:
    int solve(int start, int end) {
        if (start >= end) {
            return 0;
        }

    int mini = INT_MAX;

    for (int i=start; i<=end; i++) {
        mini = min(mini, i+max(solve(start, i-1), solve(i+1, end)));
    }

    return mini;
}

    int getMoneyAmount(int n) { 
        return solve(1, n);
    }
};