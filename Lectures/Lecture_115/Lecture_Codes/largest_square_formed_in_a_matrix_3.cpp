// tabulation method

class Solution {
  public:
    int solve(vector<vector<int>> &mat, int &maxi, int &n, int &m) {
        
        vector<vector<int>> dp(n+1, vector<int>(m+1 ,0));
        
        for (int i=n-1; i>=0; i--) {
            for (int j=m-1; j>=0; j--) {
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
                
                if (mat[i][j] == 1) {
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(maxi, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        int maxi = 0;
        
        solve(mat, maxi, n, m);
        
        return maxi;
    }
};