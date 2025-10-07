// Edit Distance - Space Optimized DP
// Reduces space complexity from O(m×n) to O(n) using only two arrays

class Solution {
public:
    int solve(string &word1, string &word2) {
        int m = word1.size();
        int n = word2.size();
        
        // Space optimization: Use only two 1D arrays instead of 2D table
        // curr[j] = current row being computed (for word1[i])
        // next[j] = next row (for word1[i+1]) - already computed
        vector<int> curr(n+1, 0);  // Current row
        vector<int> next(n+1, 0); // Next row (previously computed)

        // Initialize base case for the last row (when word1 is exhausted)
        // next[j] represents: word1 is empty, need to INSERT word2[j..end]
        for (int idx2 = 0; idx2 < n; idx2++) {
            next[idx2] = n - idx2;  // Insert remaining characters from word2
        }

        // Process each character of word1 from right to left
        for (int idx1 = m-1; idx1 >= 0; idx1--) {
            
            // Process each character of word2 from right to left
            for (int idx2 = n-1; idx2 >= 0; idx2--) {

                // Base case for current row: when word2 is exhausted
                // Need to DELETE remaining characters from word1[idx1..end]
                curr[n] = m - idx1;

                int ans = 0;

                // Case 1: Characters match - no operation needed
                if (word1[idx1] == word2[idx2]) {
                    // Take diagonal value from next row
                    ans = next[idx2+1];
                }
                else {
                    // Case 2: Characters don't match - try all 3 operations
                    
                    // INSERT operation: Insert word2[idx2] into word1
                    // Look at curr[idx2+1] - same row, next column
                    int insert = 1 + curr[idx2+1];

                    // DELETE operation: Delete word1[idx1] from word1  
                    // Look at next[idx2] - next row, same column
                    int remove = 1 + next[idx2];

                    // REPLACE operation: Replace word1[idx1] with word2[idx2]
                    // Look at next[idx2+1] - next row, next column (diagonal)
                    int replace = 1 + next[idx2+1];

                    // Take minimum of all three operations
                    ans = min(insert, min(remove, replace));
                }
                
                // Store result in current row
                curr[idx2] = ans;
            }
            
            // Move to next iteration: current row becomes next row
            next = curr;
        }
        
        // Return result for converting entire word1 to word2
        return next[0];
    }

    int minDistance(string word1, string word2) {
        // Handle edge cases
        if (word1.size() == 0) {
            return word2.size();  // Insert all characters of word2
        }

        if (word2.size() == 0) {
            return word1.size();  // Delete all characters of word1
        }

        return solve(word1, word2);
    }
};

/*
SPACE OPTIMIZATION EXPLANATION:

Time Complexity: O(m × n) - same as 2D DP
Space Complexity: O(n) - reduced from O(m × n) to O(min(m,n))

Key Optimization Insight:
- In 2D DP, dp[i][j] only depends on dp[i+1][j], dp[i][j+1], dp[i+1][j+1]
- We only need current row and next row, not the entire 2D table
- Can process row by row and discard old rows

Array Usage:
- curr[j]: Stores results for current row (word1[i])
- next[j]: Stores results for next row (word1[i+1])
- After processing each row, curr becomes next for the following iteration

Memory Access Pattern:
curr[j] depends on:
- curr[j+1] (INSERT - same row, next column)
- next[j]   (DELETE - next row, same column)  
- next[j+1] (REPLACE - next row, next column)

Why this works:
- We process columns from right to left within each row
- When computing curr[j], curr[j+1] is already computed
- next[j] and next[j+1] are from previous iteration

Space Savings:
- Original: O(m × n) for full 2D table
- Optimized: O(n) for two 1D arrays
- Can further optimize to O(min(m,n)) by choosing shorter string for columns

This is the most space-efficient solution while maintaining optimal time complexity!
*/