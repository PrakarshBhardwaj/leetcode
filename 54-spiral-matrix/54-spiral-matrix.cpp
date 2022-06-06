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
                // ans.push_back(matrix[i][j]);
                v.push_back({i, j});
            }
            
            for(int j = i; j < m - i; j++){
                // ans.push_back(matrix[j][n - 1 - i]);
                v.push_back({j, n - 1 - i});
            }
            
            for(int j = n - i - 1; j >= i; j--){
                // ans.push_back(matrix[m - i - 1][j]);
                v.push_back({m - i - 1, j});
            }
            
            for(int j = m - 1 - i; j >= i; j--){
                // ans.push_back(matrix[j][i]);
                v.push_back({j, i});
            }
            
            v.pop_back();
        }
        
        int t = 1;
        s.insert(v[0]);
        for(int i = 1; i < v.size(); i++){
            if(s.find(v[i]) != s.end()) continue;
            
            v[t] = v[i];
            s.insert(v[i]);
            t++;
        }
        
        for(int i = 0; i < t; i++){
            ans.push_back(matrix[v[i].first][v[i].second]);
        }
        
        return ans;
    }
};