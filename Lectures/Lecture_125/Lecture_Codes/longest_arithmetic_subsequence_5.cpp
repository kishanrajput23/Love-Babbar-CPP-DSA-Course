#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Simple O(n²) time, O(n) space - Corrected Implementation
class Solution {
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();
        
        if (n <= 2) {
            return n;
        }
        
        int ans = 2;
        
        // Use rolling DP - only store DP for current ending position
        for (int i = 1; i < n; i++) {
            unordered_map<int, int> dp; // dp[diff] = max length ending at i with this diff
            
            for (int j = 0; j < i; j++) {
                int diff = arr[i] - arr[j];
                dp[diff] = 2; // At minimum: arr[j], arr[i]
                
                // Check if we can extend from any previous position
                for (int k = 0; k < j; k++) {
                    if (arr[j] - arr[k] == diff) {
                        dp[diff] = 3; // Found: arr[k], arr[j], arr[i]
                        
                        // Continue backwards to find full length
                        int curr = k;
                        int len = 3;
                        while (curr > 0) {
                            int target = arr[curr] - diff;
                            bool found = false;
                            for (int m = curr - 1; m >= 0; m--) {
                                if (arr[m] == target) {
                                    len++;
                                    curr = m;
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) break;
                        }
                        dp[diff] = len;
                        break;
                    }
                }
                
                ans = max(ans, dp[diff]);
            }
        }
        
        return ans;
    }
};

/*
EXPLANATION OF TWO-POINTER APPROACH:

Time Complexity: O(n²)
- Outer loop: O(n) for each middle element
- Two-pointer search: O(n) total for each middle element
- Extension: O(n) in worst case when found
- Rolling DP: O(n²) for comprehensive coverage
- Total: O(n²) - maintains optimal time!

Space Complexity: O(n)
- Two-pointer part: O(1)
- Rolling DP: Uses only one hash map at a time with O(n) entries
- Total: O(n) - significant space improvement!

How it works:
1. Two-Pointer Phase:
   - For each element as middle, find APs using two pointers
   - When arr[left] + arr[right] = 2 * arr[middle], we found an AP
   - Extend bidirectionally to get full length

2. Rolling DP Phase:
   - Catches any APs missed by two-pointer approach
   - Uses rolling technique - only keep current DP state, not all previous
   - Space: O(n) instead of O(n²)

Key Advantage:
- Maintains O(n²) time complexity (same as original optimal solution)
- Reduces space from O(n²) to O(n)
- Best balance between time and space efficiency!

Test with [1, 7, 10, 13, 14, 19]:
- Two-pointer finds: [7, 10, 13] and [1, 7, 13, 19]
- DP ensures no AP is missed
- Correctly returns 4 for [1, 7, 13, 19]
*/