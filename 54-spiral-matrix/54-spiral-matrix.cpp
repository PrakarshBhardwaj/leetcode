class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int ln = min(m, n)/2 + (min(m, n) & 1);
        vector<pair<int, int>> v;
        set<pair<int, int>> s;
        vector<int> ans;
        
        for(int i = 0; i < ln; i++){
            
            for(int j = i; j < n - i; j++){
                if(s.find({i, j}) == s.end()){
                    v.push_back({i, j});
                    s.insert({i,j});
                }
            }
            
            for(int j = i; j < m - i; j++){
                if(s.find({j, n - 1 - i}) == s.end()){
                    v.push_back({j, n - 1 - i});  
                    s.insert({j, n - 1 - i});
                }
            }
            
            for(int j = n - i - 1; j >= i; j--){
                if(s.find({m - i - 1, j}) == s.end()){
                    v.push_back({m - i - 1, j});
                    s.insert({m - i - 1, j});
                }
            }
            
            for(int j = m - 1 - i; j >= i; j--){
                if(s.find({j, i}) == s.end()){
                    v.push_back({j, i});
                    s.insert({j, i});
                }
            }
            
            // v.pop_back();
        }
        
        for(int i = 0; i < v.size(); i++){
            ans.push_back(matrix[v[i].first][v[i].second]);
        }
        
        return ans;
    }
};