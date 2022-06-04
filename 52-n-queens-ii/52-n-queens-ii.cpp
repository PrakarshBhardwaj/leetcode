class Solution {
public:
    int cnt = 0;
    
    void go(vector<pair<int, int>> &v, int &n, int rem, int strt){
        if(rem == 0){
            cnt++;
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
    
    int totalNQueens(int n) {
        vector<pair<int, int>> v;
        go(v, n, n, 0);
        return cnt;
    }
};