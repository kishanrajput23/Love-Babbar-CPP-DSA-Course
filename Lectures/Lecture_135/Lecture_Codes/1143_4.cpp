// Space Optimized

class Solution {
public:
    int solve(string &text1, string &text2) {
        int m = text1.size();
        int n = text2.size();

        int size = max(m, n);

        vector<int> curr(size+1);
        vector<int> next(size+1);

        for (int index1=m-1; index1>=0; index1--) {
            for (int index2=n-1; index2>=0; index2--) {
                int ans = 0;

                if (text1[index1] == text2[index2]) {
                    ans = 1 + next[index2+1];
                }
                else {
                    ans = max(next[index2], curr[index2+1]);
                }

                curr[index2] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, text2);
    }
};