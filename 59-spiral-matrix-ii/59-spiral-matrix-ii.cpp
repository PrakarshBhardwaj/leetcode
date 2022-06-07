class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
    
        int ln = n/2 + (n&1);
        int t = 1;
        
        for(int i = 0; i < ln; i++){
            
            for(int j = i; j < n - i; j++){
                if(ans[i][j] == 0){
                    ans[i][j] = t;
                    t++;
                }
            }
            
            for(int j = i; j < n - i; j++){
                if(ans[j][n - 1 - i] == 0){
                    ans[j][n - 1 - i] = t;
                    t++;
                }
            }
            
            for(int j = n - i - 1; j >= i; j--){
                if(ans[n - 1 - i][j] == 0){
                    ans[n - 1 - i][j] = t;
                    t++;
                }
            }
            
            for(int j = n - 1 - i; j >= i; j--){
                if(ans[j][i] == 0){
                    ans[j][i] = t;
                    t++;
                }
            }
        }
        
        return ans;
    }
};