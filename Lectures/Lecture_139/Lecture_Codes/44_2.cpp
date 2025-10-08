/*
44. Wildcard Pattern Matching - Recursion + Memoization (Top-Down DP)
Optimized version of recursive solution using memoization to avoid recomputation

TIME COMPLEXITY: O(m × n) - Polynomial
- Each unique (i,j) pair is computed only once
- Total unique subproblems: m × n
- Each subproblem takes O(1) time (excluding recursive calls)
- Overall: O(m × n) where m = s.length, n = p.length

SPACE COMPLEXITY: O(m × n) - Quadratic
- DP table: O(m × n) for memoization storage
- Recursion stack: O(m + n) in worst case
- Total: O(m × n) dominated by DP table

OPTIMIZATION: Eliminates redundant recursive calls using memoization
*/

class Solution {
public:
    // Memoized recursive function to check pattern matching
    // dp[i][j] stores result for matching str[0..i] with pat[0..j]
    bool solve(string &str, string &pat, int i, int j, vector<vector<int>> &dp) {
        
        // Base Case 1: Both string and pattern are exhausted
        if (i < 0 && j < 0) {
            return true;
        }

        // Base Case 2: String exhausted but pattern has remaining characters
        if (i >= 0 && j < 0) {
            return false;
        }

        // Base Case 3: Pattern exhausted but string has remaining characters
        // Check if all remaining pattern characters are '*'
        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (pat[k] != '*') {
                    return false;  // Non-'*' character can't match empty string
                }
            }
            return true;  // All '*' characters can match empty string
        }

        // Check if this subproblem is already solved (memoization check)
        if (dp[i][j] != -1) {
            return dp[i][j];  // Return previously computed result
        }

        // Case 1: Exact character match OR '?' wildcard
        if (str[i] == pat[j] || pat[j] == '?') {
            // Store result in DP table and return
            return dp[i][j] = solve(str, pat, i-1, j-1, dp);
        }
        // Case 2: '*' wildcard - can match zero or more characters
        else if (pat[j] == '*') {
            // Two choices for '*':
            // Choice 1: '*' matches current character str[i] (and possibly more)
            // Choice 2: '*' matches empty sequence (skip the '*')
            return dp[i][j] = solve(str, pat, i-1, j, dp) ||  // Match current + more
                              solve(str, pat, i, j-1, dp);    // Match empty sequence
        }
        // Case 3: Characters don't match and no wildcards
        else {
            return dp[i][j] = false;  // Store false result and return
        }
    }

    // Main function with memoization setup
    bool isMatch(string s, string p) {
        // Create 2D DP table initialized with -1 (uncomputed)
        // dp[i][j] represents: does s[0..i] match p[0..j]?
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return solve(s, p, s.size()-1, p.size()-1, dp);
    }
};
