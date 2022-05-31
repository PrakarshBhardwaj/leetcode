class Solution {
public:
    int go(vector<pair<int, int>> &vp, int k, int m, int n, vector<vector<vector<int>>> &dp){
        
        if(m == 0 && n == 0){
            // for(auto lmao : idx) cout << strs[lmao] << " ";
            // cout << endl;
            return 0;
        }
        if(k < 0){
            // for(auto lmao : idx) cout << strs[lmao] << " ";
            // cout << endl;
            return 0;
        }
        
        if(dp[k][m][n] != -1) return dp[k][m][n];
        
        int ones, zeros; tie(ones, zeros) = vp[k];
        
        
        dp[k][m][n] = go(vp, k - 1, m, n, dp);
        
        if(ones <= n && zeros <= m){
            dp[k][m][n] = max(dp[k][m][n], go(vp, k - 1, m - zeros, n - ones, dp) + 1);
        }
        
        return dp[k][m][n];
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        
        vector<pair<int,int>> vp;
        
        for(int i = 0; i < k; i++){
            int c = 0, sz = strs[i].size();
            for(int j = 0; j < sz; j++) c += (strs[i][j] == '1');
            
            vp.push_back({c, sz - c});
        }
        
        vector<vector<vector<int>>> dp(k, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        
        return go(vp, k - 1, m, n, dp);
    }
};

