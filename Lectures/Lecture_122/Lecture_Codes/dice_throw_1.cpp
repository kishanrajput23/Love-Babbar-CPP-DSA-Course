// Recursion [TLE]

class Solution {
    public:
    long long solve(int dice, int faces, int target) {
        // base cases
        if (target < 0) {
            return 0;
        }
        
        if (dice == 0 && target != 0) {
            return 0;
        }
        
        if (target == 0 && dice != 0) {
            return 0;
        }
        
        if (dice == 0 && target == 0) {
            return 1;
        }
        
        // calculating all possible ways for find target sum
        int ans = 0;
        
        for (int i=1; i<=faces; i++) {
            ans += solve(dice-1, faces, target-i);
        }
        
        return ans;
        
    }
        
    long long noOfWays(int m, int n, int x) {
        // code here
        return solve(n, m, x);
    }
};