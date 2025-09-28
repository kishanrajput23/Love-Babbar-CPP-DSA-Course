//  Gives TLE

class Solution {
public:
    int solve(vector<int> &arr, map<pair<int, int>, int> &mp, int left, int right) {
        // leaf node
        if (left == right) {
            return 0;
        }

        int ans = INT_MAX;

        for (int i=left; i<right; i++) {
            ans = min(ans, mp[{left, i}] * mp[{i+1, right}] + solve(arr, mp, left, i) + solve(arr, mp, i+1, right));
        }

        return ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> mp;

        for (int i=0; i<arr.size(); i++) {
            mp[{i, i}] = arr[i];
            for (int j=i+1; j<arr.size(); j++) {
                mp[{i, j}] = max(arr[j], mp[{i, j-1}]);
            }
        }

        return solve(arr, mp, 0, arr.size()-1);
    }
};