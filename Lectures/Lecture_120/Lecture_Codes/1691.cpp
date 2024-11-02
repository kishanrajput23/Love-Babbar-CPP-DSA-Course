class Solution {
public:
    // Function to check if `newBox` can be placed on top of `base`
    bool check(vector<int> base, vector<int> newBox) {
        // Check if `newBox` dimensions are less than or equal to `base` dimensions
        // for all sides, making it possible to stack `newBox` on `base`.
        return (newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2]);
    }

    // Function to solve for maximum stack height using dynamic programming
    int solve(int n, vector<vector<int>>& cuboids) {
        // Initialize current and next rows to store DP results
        vector<int> currRow(n + 1, 0);  // Row for current DP state
        vector<int> nextRow(n + 1, 0);  // Row for next DP state

        // Traverse cuboids in reverse to build the DP table bottom-up
        for (int currIndex = n - 1; currIndex >= 0; currIndex--) {
            for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--) {
                
                // Case 1: Include the current cuboid in the stack
                int include = 0;
                if (prevIndex == -1 || check(cuboids[currIndex], cuboids[prevIndex])) {
                    // Add the height of the current cuboid to the maximum stack height
                    include = cuboids[currIndex][2] + nextRow[currIndex + 1];
                }
                
                // Case 2: Exclude the current cuboid from the stack
                int exclude = 0 + nextRow[prevIndex + 1];

                // Choose the maximum of including or excluding the current cuboid
                currRow[prevIndex + 1] = max(include, exclude);
            }
            // Move to the next row in DP table (copy `currRow` to `nextRow`)
            nextRow = currRow;
        }

        // Return the result stored in the first cell of the DP table
        return nextRow[0];
    }

    // Main function to compute maximum stack height
    int maxHeight(vector<vector<int>>& cuboids) {
        // Step 1: Sort dimensions within each cuboid to fix rotation
        for (auto &cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }

        // Step 2: Sort cuboids by dimensions to ensure valid stack order
        sort(cuboids.begin(), cuboids.end());

        // Step 3: Compute the maximum stack height using the DP solution
        return solve(cuboids.size(), cuboids);
    }
};
