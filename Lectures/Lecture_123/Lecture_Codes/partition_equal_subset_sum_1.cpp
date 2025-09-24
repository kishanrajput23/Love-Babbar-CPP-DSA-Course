// Gives TLE [Recursion]

class Solution {
  public:
    bool solve(int index, int n, vector<int> &arr, int target) {
        if (index > n) {
            return false;
        }
        
        if (target < 0) {
            return false;
        }
        
        if (target == 0) {
            return true;
        }
        
        bool include = solve(index+1, n, arr, target-arr[index]);
        bool exclude = solve(index+1, n, arr, target);
        
        return include or exclude;
    }
    
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int total = 0;
        
        for (auto i : arr) {
            total += i;
        }
        
        if (total % 2 != 0) {
            return false;
        }
        
        int target = total / 2;
        
        return solve(0, n, arr, target);
    }
};