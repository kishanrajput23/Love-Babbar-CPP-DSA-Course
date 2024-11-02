class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Step 1: Sort the envelopes by width in ascending order.
        //         If two envelopes have the same width, sort by height in descending order.
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {

            // If widths are the same, sort by height in descending order
            if (a[0] == b[0]) {
                return a[1] > b[1];  // Return true if 'a' should come before 'b' based on height
            }
            
            // Otherwise, sort by width in ascending order
            return a[0] < b[0];  // Return true if 'a' should come before 'b' based on width
        });

        int n = envelopes.size();
        
        // Step 2: Initialize a vector `ans` to keep track of the longest increasing subsequence of heights.
        //         This will represent the sequence of envelopes we can Russian doll.
        vector<int> ans;
        
        // Add the height of the first envelope to start our sequence.
        ans.push_back(envelopes[0][1]);
        
        // Step 3: Traverse through each envelope to build the longest increasing subsequence.
        for (int i = 1; i < n; i++) {
            // Check if the current envelope's height is greater than the last height in `ans`.
            // If yes, we can add it to our sequence (Russian-dolling one more envelope).
            if (envelopes[i][1] > ans.back()) {
                ans.push_back(envelopes[i][1]);
            } 
            else {
                // Otherwise, find the position where this height would fit in `ans` to keep it sorted.
                // Use binary search to find the first height in `ans` that is >= envelopes[i][1]
                int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
                
                // Replace the value at `index` with the current height to maintain an increasing sequence
                // with smaller values where possible (helps in maximizing the sequence).
                ans[index] = envelopes[i][1];
            }
        }
        
        // Step 4: The size of `ans` will be the maximum number of envelopes we can Russian doll.
        return ans.size();
    }
};
