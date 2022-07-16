class Solution {
public:
    const int M = 1e9 + 7;
    
    int go(int &m, int &n, int mx, int r, int c, vector<vector<vector<int>>> &dp){
        if(r < 0 || c < 0 || r >= m || c >= n) return 1;
        if(mx <= 0) return 0;
        
        if(dp[r][c][mx] != -1) return dp[r][c][mx];
        
        int cnt = 0;
        
        cnt += go(m, n, mx - 1, r + 1, c, dp);
        cnt %= M;
        cnt += go(m, n, mx - 1, r - 1, c, dp);
        cnt %= M;
        cnt += go(m, n, mx - 1, r, c + 1, dp);
        cnt %= M;
        cnt += go(m, n, mx - 1, r, c - 1, dp);
        cnt %= M;
        
        return dp[r][c][mx] = cnt;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return go(m, n, maxMove, startRow, startColumn, dp);
    }
};