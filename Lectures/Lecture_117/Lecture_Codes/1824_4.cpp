// Space Optimization

class Solution {
public:
    int solve(vector<int> &obstacles) {
        int n = obstacles.size()-1;
        
        vector<int> curr(4, INT_MAX);
        vector<int> next(4, INT_MAX);

        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for (int currPos=n-1; currPos>=0; currPos--) {
            for (int currLane=1; currLane<=3; currLane++) {
                if (obstacles[currPos + 1] != currLane) {
                    curr[currLane] =  next[currLane];
                }
                else {
                    int ans = 1e9;

                    for (int i=1; i<=3; i++) {
                        if (obstacles[currPos] != i && currLane != i) {
                            ans = min(ans, 1 + next[i]);
                        }
                    }

                    curr[currLane] = ans;
                }
            }
            next = curr;
        }

        return min(next[2], min(1+next[1], 1+next[3]));
    }

    int minSideJumps(vector<int>& obstacles) {
        
        return solve(obstacles);
    }
};