class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        vector<vector<bool>> flg(n, vector<bool>(n, false));
        
        int ln = n/2 + (n&1);
        int t = 1;
        
        for(int i = 0; i < ln; i++){
            
            for(int j = i; j < n - i; j++){
                if(!flg[i][j]){
                    ans[i][j] = t;
                    t++;
                    flg[i][j] = true;
                }
            }
            
            for(int j = i; j < n - i; j++){
                if(!flg[j][n - 1 - i]){
                    ans[j][n - 1 - i] = t;
                    t++;
                    flg[j][n - 1 - i] = true;
                }
            }
            
            for(int j = n - i - 1; j >= i; j--){
                if(!flg[n - 1 - i][j]){
                    ans[n - 1 - i][j] = t;
                    t++;
                    flg[n - 1 - i][j] = true;
                }
            }
            
            for(int j = n - 1 - i; j >= i; j--){
                if(!flg[j][i]){
                    ans[j][i] = t;
                    t++;
                    flg[j][i] = true;
                }
            }
        }
        
        return ans;
    }
};