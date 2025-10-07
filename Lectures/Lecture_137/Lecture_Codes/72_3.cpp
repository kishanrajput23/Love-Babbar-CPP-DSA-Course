// Edit Distance - Bottom-Up DP (Tabulation Method)
// Iterative solution that builds DP table from bottom-up

class Solution {
public:
    int solve(string &word1, string &word2) {
        int m = word1.size();
        int n = word2.size();
        
        // Create DP table with extra row and column for base cases
        // dp[i][j] = min operations to convert word1[i..] to word2[j..]
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // Initialize base cases for last row (word1 is exhausted)
        // Need to INSERT all remaining characters from word2
        for (int idx2 = 0; idx2 < n; idx2++) {
            dp[m][idx2] = n - idx2;  // Insert remaining chars from word2
        }

        // Initialize base cases for last column (word2 is exhausted)
        // Need to DELETE all remaining characters from word1
        for (int idx1 = 0; idx1 < m; idx1++) {
            dp[idx1][n] = m - idx1;  // Delete remaining chars from word1
        }

        // Fill DP table from bottom-right to top-left
        // Process in reverse order to ensure dependencies are already computed
        for (int idx1 = m-1; idx1 >= 0; idx1--) {
            for (int idx2 = n-1; idx2 >= 0; idx2--) {
                int ans = 0;

                // Case 1: Characters match - no operation needed
                if (word1[idx1] == word2[idx2]) {
                    ans = dp[idx1+1][idx2+1];  // Take diagonal value
                }
                else {
                    // Case 2: Characters don't match - try all 3 operations
                    
                    // INSERT operation: Insert word2[idx2] into word1
                    // After insert, we need to match word1[idx1..] with word2[idx2+1..]
                    int insert = 1 + dp[idx1][idx2+1];

                    // DELETE operation: Delete word1[idx1] from word1
                    // After delete, we need to match word1[idx1+1..] with word2[idx2..]
                    int remove = 1 + dp[idx1+1][idx2];

                    // REPLACE operation: Replace word1[idx1] with word2[idx2]
                    // After replace, we need to match word1[idx1+1..] with word2[idx2+1..]
                    int replace = 1 + dp[idx1+1][idx2+1];

                    // Take minimum of all three operations
                    ans = min(insert, min(remove, replace));
                }
                
                // Store result in DP table
                dp[idx1][idx2] = ans;
            }
        }
        
        // Return result for converting entire word1 to word2
        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        return solve(word1, word2);
    }
};

/*
BOTTOM-UP DP EXPLANATION:

Time Complexity: O(m × n) where m = word1.length, n = word2.length
Space Complexity: O(m × n) for DP table

Key Concepts:
1. No recursion - uses iterative approach
2. Builds solution from smaller subproblems to larger ones
3. Each cell depends only on already computed cells (right, down, diagonal)

DP Table Structure:
dp[i][j] = minimum operations to convert word1[i..end] to word2[j..end]

Fill Order: Bottom-right to top-left because:
- dp[i][j] depends on dp[i+1][j], dp[i][j+1], dp[i+1][j+1]
- We need to compute dependencies before current cell

Example for word1="horse", word2="ros":
    ""  s   o   r
""   3   2   1   0
e    4   3   2   1
s    5   4   3   2  
r    6   5   4   3
o    7   6   5   4
h    8   7   6   5

Base cases:
- Last row: Converting empty string to remaining word2 chars
- Last column: Converting remaining word1 chars to empty string

Advantages over memoization:
- No recursion stack overhead
- Predictable memory access pattern
- Easier to optimize further (space optimization)
*/