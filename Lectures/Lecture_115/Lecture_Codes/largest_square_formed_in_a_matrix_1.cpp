// Gives TLE

class Solution {
  public:
    int solve(vector<vector<int>> &mat, int i, int j, int &maxi, int &n, int &m) {
        if (i >= n || j >= m) {
            return 0;
        } 
        
        int right = solve(mat, i, j+1, maxi, n, m);
        int diagonal = solve(mat, i+1, j+1, maxi, n, m);
        int down = solve(mat, i+1, j, maxi, n, m);
        
        if (mat[i][j] == 1) {
            int ans = 1 + min(right, min(diagonal, down));
            
            maxi = max(maxi, ans);
            
            return ans;
        }
        else {
            return 0;
        }
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        int maxi = 0;
        
        solve(mat, 0, 0, maxi, n, m);
        
        return maxi;
    }
};