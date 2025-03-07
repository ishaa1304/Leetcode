class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Iterate over rows first, then columns
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];  // Base case
                } else {
                    int up = 1e9, left = 1e9; // Initialize to a large number
                    
                    if (i > 0) {
                        up = dp[i-1][j] + grid[i][j]; // Moving down
                    }
                    
                    if (j > 0) {
                        left = dp[i][j-1] + grid[i][j]; // Moving right
                    }

                    dp[i][j] = min(up, left);
                }
            }
        }
        
        return dp[m-1][n-1]; // Return minimum path sum to bottom-right
    }
};
