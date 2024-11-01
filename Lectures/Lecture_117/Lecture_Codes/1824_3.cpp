// tabulation method

class Solution {
public:
    int solve(vector<int> &obstacles) {
        int n = obstacles.size()-1;
        vector<vector<int>>dp(4, vector<int>(obstacles.size(), 1e9));

        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for (int currPos=n-1; currPos>=0; currPos--) {
            for (int currLane=1; currLane<=3; currLane++) {
                if (obstacles[currPos + 1] != currLane) {
                    dp[currLane][currPos] =  dp[currLane][currPos+1];
                }
                else {
                    int ans = 1e9;

                    for (int i=1; i<=3; i++) {
                        if (obstacles[currPos] != i && currLane != i) {
                            ans = min(ans, 1 + dp[i][currPos+1]);
                        }
                    }

                    dp[currLane][currPos] = ans;
                }
            }
        }

        return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));
    }

    int minSideJumps(vector<int>& obstacles) {
        
        return solve(obstacles);
    }
};