/*
44. Wildcard Pattern Matching - Bottom-Up DP (Tabulation Method)
Iterative solution that builds DP table from base cases to final result

TIME COMPLEXITY: O(m × n) - Polynomial
- Two nested loops: outer loop runs m times, inner loop runs n times
- Each cell computation takes O(1) time
- Total operations: m × n cell computations
- m = s.length, n = p.length

SPACE COMPLEXITY: O(m × n) - Quadratic
- 2D DP table: (m+1) × (n+1) = O(m × n) space
- No recursion stack overhead (iterative approach)
- Additional variables: O(1) space
- Total: O(m × n) for DP table

ADVANTAGE: No recursion stack, better cache locality, easier to optimize
*/

class Solution {
public:
    bool solve(string &str, string &pat) {
        int m = str.size();
        int n = pat.size();
        
        // Create DP table with 1-based indexing
        // dp[i][j] = true if str[0..i-1] matches pat[0..j-1]
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // Base Case 1: Empty string matches empty pattern
        dp[0][0] = true;

        // Base Case 2: Initialize first row (empty string vs pattern prefixes)
        // Empty string can only match pattern if pattern consists entirely of '*'
        for (int j = 1; j <= n; j++) {
            bool flag = true;
            
            // Check if pattern[0..j-1] consists only of '*' characters
            for (int k = 1; k <= j; k++) {
                if (pat[k-1] != '*') {
                    flag = false;  // Found non-'*' character
                    break;
                }
            }
            dp[0][j] = flag;  // true if all characters are '*', false otherwise
        }

        // Note: First column (dp[i][0] for i>0) is automatically false
        // Non-empty string cannot match empty pattern
        // This is handled by initialization with 0

        // Fill DP table iteratively
        for (int i = 1; i <= m; i++) {           // For each character in string
            for (int j = 1; j <= n; j++) {       // For each character in pattern
                
                // Case 1: Characters match exactly OR pattern has '?'
                if (str[i-1] == pat[j-1] || pat[j-1] == '?') {
                    // Current characters match, result depends on previous characters
                    dp[i][j] = dp[i-1][j-1];
                }
                // Case 2: Pattern has '*' wildcard
                else if (pat[j-1] == '*') {
                    // '*' can match in two ways:
                    // Option 1: '*' matches current character str[i-1] (and possibly more)
                    //           Take result from dp[i-1][j] (consume string char, keep pattern)
                    // Option 2: '*' matches empty sequence  
                    //           Take result from dp[i][j-1] (keep string char, consume pattern)
                    dp[i][j] = dp[i-1][j] ||     // '*' matches str[i-1] + more
                               dp[i][j-1];       // '*' matches empty sequence
                }
                // Case 3: Characters don't match and no wildcards
                else {
                    dp[i][j] = false;  // No match possible
                }
            }
        }

        // Return result for matching entire string with entire pattern
        return dp[m][n];
    }

    // Main function for bottom-up approach
    bool isMatch(string s, string p) {
        return solve(s, p);
    }
};
