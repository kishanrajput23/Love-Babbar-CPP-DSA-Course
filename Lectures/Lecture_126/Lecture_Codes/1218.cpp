class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;

        int ans = 0;

        for (int i=0; i<arr.size(); i++) {
            int temp = arr[i] - difference;
            int tempAns = 0;

            // check if answer already exist for temp in dp
            if (dp.count(temp)) {
                tempAns = dp[temp];
            }

            // update current answer
            dp[arr[i]] = 1 + tempAns;

            // update answer
            ans = max(ans, dp[arr[i]]);
        }

        return ans;
    }
};