/*
44. Wildcard Pattern Matching - Space Optimized DP
Reduces space complexity from O(m×n) to O(n) using only two arrays

TIME COMPLEXITY: O(m × n) - Polynomial
- Same as tabulation method: two nested loops
- Outer loop: m iterations (for each string character)
- Inner loop: n iterations (for each pattern character)  
- Each cell computation: O(1) time
- Total: O(m × n) where m = s.length, n = p.length

SPACE COMPLEXITY: O(n) - Linear (OPTIMIZED!)
- Two 1D arrays: prev[n+1] and curr[n+1] = O(2n) = O(n)
- No 2D table needed: reduced from O(m × n) to O(n)
- Additional variables: O(1) space
- Total: O(n) where n = p.length (pattern length)

OPTIMIZATION: Best space complexity while maintaining optimal time!
*/

class Solution {
public:
    bool solve(string &str, string &pat) {
        int m = str.size();
        int n = pat.size();
        
        // Space optimization: Use only two 1D arrays instead of 2D table
        // prev[j] = result for previous row (str[0..i-2] vs pat[0..j-1])  
        // curr[j] = result for current row (str[0..i-1] vs pat[0..j-1])
        vector<int> prev(n+1, 0);  // Previous row
        vector<int> curr(n+1, 0);  // Current row

        // Base Case 1: Empty string matches empty pattern
        prev[0] = true;

        // Base Case 2: Initialize first row (empty string vs pattern prefixes)
        // Empty string can only match if pattern consists entirely of '*'
        for (int j = 1; j <= n; j++) {
            bool flag = true;
            
            // Check if pattern[0..j-1] consists only of '*' characters
            for (int k = 1; k <= j; k++) {
                if (pat[k-1] != '*') {
                    flag = false;  // Found non-'*' character
                    break;
                }
            }
            prev[j] = flag;  // Store in previous row
        }

        // Process each character of string
        for (int i = 1; i <= m; i++) {
            // Reset current row (curr[0] = false for non-empty string vs empty pattern)
            curr[0] = false;
            
            // Process each character of pattern
            for (int j = 1; j <= n; j++) {
                
                // Case 1: Characters match exactly OR pattern has '?'
                if (str[i-1] == pat[j-1] || pat[j-1] == '?') {
                    // Take diagonal value from previous row
                    curr[j] = prev[j-1];
                }
                // Case 2: Pattern has '*' wildcard
                else if (pat[j-1] == '*') {
                    // Two choices for '*':
                    // Choice 1: '*' matches current character str[i-1] 
                    //           Take value from prev[j] (previous row, same column)
                    // Choice 2: '*' matches empty sequence
                    //           Take value from curr[j-1] (current row, previous column)
                    curr[j] = prev[j] ||     // '*' matches str[i-1] + previous chars
                              curr[j-1];     // '*' matches empty sequence
                }
                // Case 3: Characters don't match and no wildcards
                else {
                    curr[j] = false;  // No match possible
                }
            }
            
            // Move to next iteration: current row becomes previous row
            prev = curr;
        }

        // Return result for matching entire string with entire pattern
        return prev[n];
    }

    // Main function for space-optimized approach
    bool isMatch(string s, string p) {
        return solve(s, p);
    }
};
