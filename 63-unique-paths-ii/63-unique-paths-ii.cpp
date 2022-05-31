class Solution {
public:
    int go(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp){
        int n = grid.size(), m = grid[0].size();
        
        if(i < 0 || j < 0 || i >= n || j >= m) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(grid[i][j]) return dp[i][j] = 0;
        
        if(i == 0 && j == 0) return dp[i][j] = 1;
        
        
        return dp[i][j] = go(grid, i - 1, j, dp) + go(grid, i, j - 1, dp);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return go(grid, n - 1, m - 1, dp);
    }
};