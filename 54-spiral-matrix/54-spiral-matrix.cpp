class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int ln = min(m, n)/2 + (min(m, n) & 1);
        set<pair<int, int>> s;
        vector<int> ans;
        
        for(int i = 0; i < ln; i++){
            
            for(int j = i; j < n - i; j++){
                if(s.find({i, j}) == s.end()){
                    ans.push_back(matrix[i][j]);
                    s.insert({i,j});
                }
            }
            
            for(int j = i; j < m - i; j++){
                if(s.find({j, n - 1 - i}) == s.end()){
                    ans.push_back(matrix[j][n - 1 - i]);
                    s.insert({j, n - 1 - i});
                }
            }
            
            for(int j = n - i - 1; j >= i; j--){
                if(s.find({m - i - 1, j}) == s.end()){
                    ans.push_back(matrix[m - i - 1][j]);
                    s.insert({m - i - 1, j});
                }
            }
            
            for(int j = m - 1 - i; j >= i; j--){
                if(s.find({j, i}) == s.end()){
                    ans.push_back(matrix[j][i]);
                    s.insert({j, i});
                }
            }
        }
        
        return ans;
    }
};