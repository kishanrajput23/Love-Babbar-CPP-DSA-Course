// Recursion + Memoization

class Solution {
public:
    int solve(vector<int> &obstacles, int currLane, int currPos, vector<vector<int>> &dp) {
        int n = obstacles.size()-1;

        if (currPos == n) {
            return 0;
        }

        if (dp[currLane][currPos] != -1) {
            return dp[currLane][currPos];
        }

        if (obstacles[currPos + 1] != currLane) {
            return solve(obstacles, currLane, currPos+1, dp);
        }
        else {
            int ans = INT_MAX;

            for (int i=1; i<=3; i++) {
                if (obstacles[currPos] != i && currLane != i) {
                    ans = min(ans, 1 + solve(obstacles, i, currPos, dp));
                }
            }

            dp[currLane][currPos] = ans;

            return dp[currLane][currPos];
        }
    }

    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>>dp(4, vector<int>(n, -1));
        return solve(obstacles, 2, 0, dp);
    }
};