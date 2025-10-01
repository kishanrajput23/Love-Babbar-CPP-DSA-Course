// Gives TLE

class Solution {
public:
    int solve(string &text1, string &text2, int index1, int index2) {
        if (index1 == text1.size() || index2 == text2.size()) {
            return 0;
        }

        int ans = 0;

        if (text1[index1] == text2[index2]) {
            ans = 1 + solve(text1, text2, index1+1, index2+1);
        }
        else {
            ans = max(solve(text1, text2, index1+1, index2), solve(text1, text2, index1, index2+1));
        }

        return ans;
    }

    int longestPalindromeSubseq(string s) {
        string revStr = s;
        reverse(revStr.begin(), revStr.end());

        int ans = solve(s, revStr, 0, 0);

        return ans;
    }
};
