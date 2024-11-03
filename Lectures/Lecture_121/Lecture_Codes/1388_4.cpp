// Space Optimization 

class Solution {
public:
    int solve(vector<int>& slices) {
        int k = slices.size();

        vector<int> prev1(k+2, 0);
        vector<int> curr1(k+2, 0);
        vector<int> next1(k+2, 0);

        for (int index=k-2; index>=0; index--) {
            for (int n=1; n<=k/3; n++) {
                int take = slices[index] + next1[n-1];

                int notTake = 0 + curr1[n];

                prev1[n] = max(take, notTake);
            }

            next1 = curr1;
            curr1 = prev1;
        }

        int case1 = curr1[k/3];

        vector<int> prev2(k+2, 0);
        vector<int> curr2(k+2, 0);
        vector<int> next2(k+2, 0);

        for (int index=k-1; index>=1; index--) {
            for (int n=1; n<=k/3; n++) {
                int take = slices[index] + next2[n-1];

                int notTake = 0 + curr2[n];

                prev2[n] = max(take, notTake);
            }

            next2 = curr2;
            curr2 = prev2;
        }

        int case2 = curr2[k/3];

        return max(case1, case2);
    }

    int maxSizeSlices(vector<int>& slices) {

        return solve(slices);
    }
};