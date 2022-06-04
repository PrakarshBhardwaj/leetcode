class Solution {
public:
   vector<vector<string>> ans;
    
    void make_ans(vector<pair<int, int>> &v, int &n){
        vector<string> s(n, string(n, '.'));
        
        for(int i = 0; i < v.size(); i++){
            s[v[i].first][v[i].second] = 'Q';
        }
        
        ans.push_back(s);
    }
    
    void go(vector<pair<int, int>> &v, int &n, int rem, int strt){
        if(rem == 0){
            make_ans(v, n);
            return;
        }
        
        for(int i = strt; i < n; i++){
            for(int j = 0; j < n; j++){
                bool flg = true;
                
                for(int k = 0; k < v.size(); k++){
                    if(v[k].first == i || v[k].second == j || (i - j == v[k].first - v[k].second) || v[k].first + v[k].second == i + j){
                        flg = false;
                        break;
                    }
                }
                
                if(flg){
                    v.push_back({i, j});
                    go(v, n, rem - 1, i + 1);
                    v.pop_back();
                }
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<pair<int, int>> v;
        go(v, n, n, 0);
        return ans;
    }
};