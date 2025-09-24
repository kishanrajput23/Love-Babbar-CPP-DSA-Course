// Simplest O(1) space solution (O(n³) time
class SolutionOptimalSpace {
  public:
    int lengthOfLongestAP(vector<int>& arr) {
        int n = arr.size();
        
        if (n <= 2) {
            return n;
        }
        
        int ans = 2;
        
        // For each pair as starting elements, extend forward
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = arr[j] - arr[i];
                int length = 2;
                int last = arr[j];
                
                // Extend this AP forward
                for (int k = j + 1; k < n; k++) {
                    if (arr[k] == last + diff) {
                        length++;
                        last = arr[k];
                    }
                }
                
                ans = max(ans, length);
            }
        }
        
        return ans;
    }
};