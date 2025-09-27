/*
WHY CATALAN NUMBERS?

The problem of counting unique BSTs is equivalent to counting Catalan numbers because:

1. For n nodes, we can choose any node as root (say node k, where 1 ≤ k ≤ n)
2. Left subtree will have (k-1) nodes with values {1, 2, ..., k-1}
3. Right subtree will have (n-k) nodes with values {k+1, k+2, ..., n}
4. Number of ways = C(k-1) * C(n-k) for each choice of root k
5. Total = sum of C(k-1) * C(n-k) for k = 1 to n
6. This is exactly the recurrence relation for Catalan numbers!
*/

// Solution using Catalan Numbers
// The number of unique BSTs with n nodes = nth Catalan number

// Time Complexity: O(n²)
// Space Complexity: O(n) for DP array
class Solution {
public:
    int numTrees(int n) {
        // Method 1: Using Catalan Number Formula
        // Cn = (2n)! / ((n+1)! * n!)
        // But this can overflow, so we use iterative approach
        
        if (n <= 1) return 1;
        
        // Calculate nth Catalan number using the recurrence:
        // C(n) = sum(C(i) * C(n-1-i)) for i = 0 to n-1
        vector<long long> catalan(n + 1, 0);
        catalan[0] = 1; // C(0) = 1
        catalan[1] = 1; // C(1) = 1
        
        // Fill catalan numbers using DP
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - 1 - j];
            }
        }
        
        return catalan[n];
    }
};

// Alternative: Direct Catalan Number Formula (optimized to avoid overflow)
// Time Complexity: O(n) [Iterative]
// Space Complexity: O(1)
class SolutionOptimized {
public:
    int numTrees(int n) {
        if (n <= 1) return 1;
        
        // Use the formula: C(n) = C(n-1) * 2 * (2n-1) / (n+1)
        long long result = 1;
        
        for (int i = 2; i <= n; i++) {
            result = result * 2 * (2 * i - 1) / (i + 1);
        }
        
        return result;
    }
};

// Most Direct Formula Implementation
// Time Complexity: O(n) [Direct]
// Space Complexity: O(1)
class SolutionDirect {
public:
    int numTrees(int n) {
        if (n <= 1) return 1;
        
        // Direct calculation of nth Catalan number
        // C(n) = (2n choose n) / (n+1)
        long long result = 1;
        
        // Calculate (2n choose n) = (2n)! / (n! * n!)
        // We compute this as: (2n * (2n-1) * ... * (n+1)) / (n!)
        for (int i = 0; i < n; i++) {
            result = result * (2 * n - i) / (i + 1);
        }
        
        // Divide by (n+1) to get Catalan number
        return result / (n + 1);
    }
};
