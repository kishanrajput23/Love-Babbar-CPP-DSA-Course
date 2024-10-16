// space optimization

class Solution {
  public:
    int solve(vector<vector<int>> &mat, int &maxi, int &n, int &m) {
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);
        
        for (int i=n-1; i>=0; i--) {
            for (int j=m-1; j>=0; j--) {
                int right = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];
                
                if (mat[i][j] == 1) {
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, curr[j]);
                }
                else {
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        return next[0];
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        int maxi = 0;
        
        solve(mat, maxi, n, m);
        
        return maxi;
    }
};