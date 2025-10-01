// Bottom Up DP 

class Solution {
public:
    int solve(string &text1, string &text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int index1=m-1; index1>=0; index1--) {
            for (int index2=n-1; index2>=0; index2--) {
                int ans = 0;

                if (text1[index1] == text2[index2]) {
                    ans = 1 + dp[index1+1][index2+1];
                }
                else {
                    ans = max(dp[index1+1][index2], dp[index1][index2+1]);
                }

                dp[index1][index2] = ans;
            }
        }
        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, text2);
    }
};