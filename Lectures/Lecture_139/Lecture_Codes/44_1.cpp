/*
44. Wildcard Pattern Matching - Recursive Solution (TLE)
Problem: Match string s with pattern p containing '?' and '*'
- '?' matches any single character
- '*' matches any sequence of characters (including empty)

Approach: Recursion from end of both strings

TIME COMPLEXITY: O(2^(m+n)) - Exponential
- For each '*' wildcard, we make 2 recursive calls
- In worst case, pattern has many '*' characters
- Each '*' doubles the number of recursive calls
- Results in exponential time complexity

SPACE COMPLEXITY: O(m+n) - Linear
- Recursion stack depth is at most m+n
- Each recursive call uses O(1) space
- No additional data structures used

STATUS: Gets TLE for large inputs due to exponential time complexity
*/

class Solution {
public:
    // Recursive function to check if str[0..i] matches pat[0..j]
    // i: current index in string (processing backwards)
    // j: current index in pattern (processing backwards)
    bool solve(string &str, string &pat, int i, int j) {
        
        // Base Case 1: Both string and pattern are exhausted
        // Successfully matched entire string with entire pattern
        if (i < 0 && j < 0) {
            return true;
        }

        // Base Case 2: String is exhausted but pattern still has characters
        // This means pattern is longer than string - no match possible
        if (i >= 0 && j < 0) {
            return false;
        }

        // Base Case 3: Pattern is exhausted but string still has characters
        // Check if remaining pattern consists only of '*' characters
        // '*' can match empty sequence, so multiple '*' can all match empty
        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (pat[k] != '*') {
                    return false;  // Found non-'*' character, can't match empty string
                }
            }
            return true;  // All remaining characters are '*', can match empty string
        }

        // Case 1: Characters match exactly OR pattern has '?'
        // '?' can match any single character, so treat it as exact match
        if (str[i] == pat[j] || pat[j] == '?') {
            // Both characters are consumed, move to previous positions
            return solve(str, pat, i-1, j-1);
        }
        // Case 2: Pattern has '*' wildcard
        else if (pat[j] == '*') {
            // '*' can match in two ways:
            // Option 1: '*' matches current character str[i] (and possibly more)
            //           Move string pointer back, keep pattern pointer (star can match more)
            // Option 2: '*' matches empty sequence
            //           Keep string pointer, move pattern pointer back
            return solve(str, pat, i-1, j) ||    // '*' matches str[i] + more chars
                   solve(str, pat, i, j-1);      // '*' matches empty sequence
        }
        // Case 3: Characters don't match and pattern is not wildcard
        else {
            return false;  // No match possible
        }
    }

    // Main function to check if string s matches pattern p
    bool isMatch(string s, string p) {
        // Start matching from the end of both strings
        // This approach works backwards from last characters
        return solve(s, p, s.size()-1, p.size()-1);
    }
};
