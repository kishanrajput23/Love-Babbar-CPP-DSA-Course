// Edit Distance - Recursive Solution (Gives TLE)

class Solution {
public:
    // Recursive function to solve edit distance
    // idx1: current index in word1
    // idx2: current index in word2
    // Returns: minimum operations needed to convert word1[idx1..] to word2[idx2..]
    int solve(string &word1, string &word2, int idx1, int idx2) {
        
        // Base Case 1: If we've processed all characters of word1
        // We need to INSERT all remaining characters of word2
        if (idx1 == word1.size()) {
            return word2.size() - idx2;  // Insert remaining chars from word2
        }

        // Base Case 2: If we've processed all characters of word2
        // We need to DELETE all remaining characters of word1
        if (idx2 == word2.size()) {
            return word1.size() - idx1;  // Delete remaining chars from word1
        }

        int ans = 0;

        // Case 1: Characters match - no operation needed
        // Move both pointers forward
        if (word1[idx1] == word2[idx2]) {
            ans = solve(word1, word2, idx1+1, idx2+1);
        }
        else {
            // Case 2: Characters don't match - try all 3 operations
            
            // Operation 1: INSERT word2[idx2] into word1
            // After insertion, word2[idx2] is matched, so move idx2 forward
            // idx1 stays same as we inserted before current position
            int insert = 1 + solve(word1, word2, idx1, idx2+1);

            // Operation 2: DELETE word1[idx1] from word1  
            // After deletion, move idx1 forward, idx2 stays same
            int remove = 1 + solve(word1, word2, idx1+1, idx2);

            // Operation 3: REPLACE word1[idx1] with word2[idx2]
            // After replacement, both characters match, so move both pointers
            int replace = 1 + solve(word1, word2, idx1+1, idx2+1);

            // Take minimum of all three operations
            ans = min(insert, min(remove, replace));
        }

        return ans;
    }

    // Main function to calculate minimum edit distance
    int minDistance(string word1, string word2) {
        // Start from beginning of both strings (index 0, 0)
        return solve(word1, word2, 0 , 0);
    }
};

/*
ALGORITHM EXPLANATION:

This is a classic Dynamic Programming problem solved using recursion.

Time Complexity: O(3^(m+n)) - Exponential (TLE for large inputs)
Space Complexity: O(m+n) - Recursion stack depth

Why TLE?
- For each mismatched character, we explore 3 possibilities
- Many subproblems are solved repeatedly
- No memoization to store already computed results

Example Trace for word1="horse", word2="ros":
solve("horse", "ros", 0, 0)
├── h != r, so try:
    ├── insert 'r': 1 + solve("horse", "ros", 0, 1)
    ├── delete 'h': 1 + solve("horse", "ros", 1, 0) 
    └── replace 'h' with 'r': 1 + solve("horse", "ros", 1, 1)

This recursion continues until base cases are reached.

Next optimizations:
1. Add memoization (Top-down DP)
2. Convert to tabulation (Bottom-up DP)
3. Space optimize to O(min(m,n))
*/