// Edit Distance - Recursion + Memoization (Top-Down DP)
// Optimized version of recursive solution using memoization

class Solution {
public:
    // Memoized recursive function to solve edit distance
    // dp[idx1][idx2] stores the minimum operations for word1[idx1..] to word2[idx2..]
    int solve(string &word1, string &word2, int idx1, int idx2, vector<vector<int>> &dp) {
        
        // Base Case 1: If word1 is exhausted
        // Need to INSERT all remaining characters of word2
        if (idx1 == word1.size()) {
            return word2.size() - idx2;
        }

        // Base Case 2: If word2 is exhausted  
        // Need to DELETE all remaining characters of word1
        if (idx2 == word2.size()) {
            return word1.size() - idx1;
        }

        // Check if this subproblem is already solved (memoization)
        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }

        int ans = 0;

        // Case 1: Characters match - no operation needed
        if (word1[idx1] == word2[idx2]) {
            ans = solve(word1, word2, idx1+1, idx2+1, dp);
        }
        else {
            // Case 2: Characters don't match - try all 3 operations
            
            // INSERT operation: Insert word2[idx2] into word1
            int insert = 1 + solve(word1, word2, idx1, idx2+1, dp);

            // DELETE operation: Delete word1[idx1] from word1
            int remove = 1 + solve(word1, word2, idx1+1, idx2, dp);

            // REPLACE operation: Replace word1[idx1] with word2[idx2]
            int replace = 1 + solve(word1, word2, idx1+1, idx2+1, dp);

            // Take minimum of all three operations
            ans = min(insert, min(remove, replace));
        }

        // Store result in DP table and return (memoization)
        return dp[idx1][idx2] = ans;
    }

    // Main function with memoization setup
    int minDistance(string word1, string word2) {
        // Create 2D DP table initialized with -1
        // dp[i][j] = min operations to convert word1[i..] to word2[j..]
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return solve(word1, word2, 0 , 0, dp);
    }
};

/*
MEMOIZATION OPTIMIZATION:

Time Complexity: O(m × n) where m = word1.length, n = word2.length
Space Complexity: O(m × n) for DP table + O(m + n) for recursion stack

Key Improvements over pure recursion:
1. Each subproblem (idx1, idx2) is solved only once
2. Results are stored in dp[idx1][idx2] for future use
3. Eliminates redundant recursive calls

DP State Definition:
dp[i][j] = minimum operations to convert word1[i..end] to word2[j..end]

Why this works:
- Overlapping subproblems: Same (idx1, idx2) pairs occur multiple times
- Optimal substructure: Optimal solution contains optimal solutions to subproblems
- Memoization stores results to avoid recomputation

Example for word1="horse", word2="ros":
dp[0][0] represents converting "horse" to "ros"
dp[1][1] represents converting "orse" to "os"
etc.

This approach is much faster than pure recursion but still uses O(m×n) space.
*/