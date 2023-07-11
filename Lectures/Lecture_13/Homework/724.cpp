class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int lsum = 0;
        int rsum = 0;

        for (auto i:nums) {
            rsum += i;
        }

        for (int j=0; j<nums.size(); j++) {
            rsum -= nums[j];

            if (lsum == rsum) {
                return j;
            }

            lsum += nums[j];
        }
        return -1;
    }
};