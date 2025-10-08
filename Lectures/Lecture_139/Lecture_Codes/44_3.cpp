/*
44. Wildcard Pattern Matching - Memoization with 1-Based Indexing
Same algorithm as 44_2 but uses 1-based indexing to avoid negative index handling

TIME COMPLEXITY: O(m × n) - Polynomial
- Identical to 44_2 solution in terms of time complexity
- Each subproblem (i,j) computed exactly once
- Total subproblems: (m+1) × (n+1) = O(m × n)
- m = s.length, n = p.length

SPACE COMPLEXITY: O(m × n) - Quadratic  
- DP table: O((m+1) × (n+1)) = O(m × n) for memoization
- Recursion stack: O(m + n) maximum depth
- Total: O(m × n) dominated by DP table

ADVANTAGE: Cleaner base case handling with 1-based indexing
*/

class Solution {
public:
    // Memoized recursive function with 1-based indexing
    // i: represents length of string prefix (1 to m)
    // j: represents length of pattern prefix (1 to n)
    // dp[i][j] = result for matching s[0..i-1] with p[0..j-1]
    bool solve(string &str, string &pat, int i, int j, vector<vector<int>> &dp) {
        
        // Base Case 1: Both string and pattern are empty (length 0)
        if (i == 0 && j == 0) {
            return true;  // Empty string matches empty pattern
        }

        // Base Case 2: String has characters but pattern is empty
        if (i > 0 && j == 0) {
            return false;  // Non-empty string can't match empty pattern
        }

        // Base Case 3: String is empty but pattern has characters
        // Check if all remaining pattern characters are '*'
        if (i == 0 && j > 0) {
            for (int k = 1; k <= j; k++) {
                if (pat[k-1] != '*') {  // Convert to 0-based for actual string access
                    return false;  // Non-'*' character can't match empty string
                }
            }
            return true;  // All characters are '*', can match empty string
        }

        // Memoization check: return previously computed result
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Case 1: Characters match exactly OR pattern has '?'
        // Note: Use (i-1) and (j-1) to convert to 0-based indexing for string access
        if (str[i-1] == pat[j-1] || pat[j-1] == '?') {
            // Both characters consumed, reduce both lengths by 1
            return dp[i][j] = solve(str, pat, i-1, j-1, dp);
        }
        // Case 2: Pattern has '*' wildcard
        else if (pat[j-1] == '*') {
            // '*' can match in two ways:
            // Choice 1: '*' matches current character str[i-1] (consume string char, keep pattern)
            // Choice 2: '*' matches empty sequence (keep string char, consume pattern char)
            return dp[i][j] = solve(str, pat, i-1, j, dp) ||  // '*' matches str[i-1]
                              solve(str, pat, i, j-1, dp);    // '*' matches empty
        }
        // Case 3: Characters don't match and no wildcards
        else {
            return dp[i][j] = false;
        }
    }

    // Main function with 1-based indexing setup
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        
        // Create DP table with size (m+1) x (n+1) for 1-based indexing
        // dp[i][j] represents: does s[0..i-1] match p[0..j-1]?
        // Index 0 represents empty string/pattern
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        // Start with full lengths (1-based)
        return solve(s, p, m, n, dp);
    }
};
