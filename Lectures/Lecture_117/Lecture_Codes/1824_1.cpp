// Recursion --> Gives TLE

class Solution {
public:
    int solve(vector<int> &obstacles, int currLane, int currPos) {
        int n = obstacles.size()-1;

        if (currPos == n) {
            return 0;
        }

        if (obstacles[currPos + 1] != currLane) {
            return solve(obstacles, currLane, currPos+1);
        }
        else {
            int ans = INT_MAX;
            for (int i=1; i<=3; i++) {
                if (obstacles[currPos] != i && currLane != i) {
                    ans = min(ans, 1 + solve(obstacles, i, currPos));
                }
            }
            return ans;
        }
    }

    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles, 2, 0);
    }
};