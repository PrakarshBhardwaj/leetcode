class Solution {
public:
    int go(vector<vector<int>> &grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return 0;
        
        if(grid[i][j] == 0) return 0;
        
        grid[i][j] = 0;
        
        return go(grid, i + 1, j) + go(grid, i -1, j) + go(grid, i, j + 1) + go(grid, i, j - 1) + 1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ar = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    ar = max(ar, go(grid, i, j));
                }
            }
        }
        
        return ar;
    }
};