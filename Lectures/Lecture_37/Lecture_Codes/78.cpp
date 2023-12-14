class Solution {
public:

    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int> >& ans) {

        if (index >= nums.size()) {
            ans.push_back(output);
            return ;
        }

        // excluding the current element
        solve(nums, output, index+1, ans);

        // including the current element
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans);
    }
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;
    }
};