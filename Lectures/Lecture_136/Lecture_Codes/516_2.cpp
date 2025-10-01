// Recursion + Memoization (Top Down DP)

class Solution {
public:
    int solve(string &text1, string &text2, int index1, int index2, vector<vector<int>> &dp) {
        if (index1 == text1.size() || index2 == text2.size()) {
            return 0;
        }

        if (dp[index1][index2] != -1) {
            return dp[index1][index2];
        }

        int ans = 0;

        if (text1[index1] == text2[index2]) {
            ans = 1 + solve(text1, text2, index1+1, index2+1, dp);
        }
        else {
            ans = max(solve(text1, text2, index1+1, index2, dp), solve(text1, text2, index1, index2+1, dp));
        }

        return dp[index1][index2] = ans;
    }

    int longestPalindromeSubseq(string s) {
        string revStr = s;
        reverse(revStr.begin(), revStr.end());
        
        vector<vector<int>> dp(s.size(), vector<int>(revStr.size(), -1));

        int ans = solve(s, revStr, 0, 0, dp);

        return ans;
    }
};
