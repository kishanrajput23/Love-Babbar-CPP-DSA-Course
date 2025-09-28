// Recursion + Memoization (Top-Down DP)
// Time Complexity: O(n³)
// Space Complexity: O(n²)

class Solution {
public:
    int solve(vector<int> &arr, map<pair<int, int>, int> &mp, int left, int right, vector<vector<int>> &dp) {
        // leaf node
        if (left == right) {
            return 0;
        }

        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        int ans = INT_MAX;

        for (int i=left; i<right; i++) {
            ans = min(ans, mp[{left, i}] * mp[{i+1, right}] + solve(arr, mp, left, i, dp) + solve(arr, mp, i+1, right, dp));
        }

        return dp[left][right] = ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int, int>, int> mp;

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        for (int i=0; i<arr.size(); i++) {
            mp[{i, i}] = arr[i];
            for (int j=i+1; j<arr.size(); j++) {
                mp[{i, j}] = max(arr[j], mp[{i, j-1}]);
            }
        }

        return solve(arr, mp, 0, n-1, dp);
    }
};