// recusion --> gives TLE

class Solution {
public:
    int solve(vector<int> &values, int i, int j) {
        if (i+1 == j) {
            return 0;
        }

        int ans = INT_MAX;

        for (int k=i+1; k<j; k++) {
            ans = min(ans, values[i]*values[j]*values[k] + solve(values, i, k) + solve(values, k, j));
        }

        return ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        return solve(values, 0, n-1);
    }
};