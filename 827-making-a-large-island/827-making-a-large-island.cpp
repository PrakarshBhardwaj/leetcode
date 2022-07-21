class Solution {
public:
    const int dx[4] = {1,0,-1,0};
    const int dy[4] = {0,1,0,-1};
    
    bool isvalid(int &m, int &n, int i, int j){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    
    pair<int, int> find(vector<vector<pair<int, int>>> &dsu, int i, int j){
        if(i == dsu[i][j].first && j == dsu[i][j].second) return dsu[i][j];
        return dsu[i][j] = find(dsu, dsu[i][j].first, dsu[i][j].second);
    }
    
    void uni(vector<vector<pair<int, int>>> &dsu, vector<vector<int>> &sz, int i, int j, int a, int b){
        pair<int, int> t1 = find(dsu, i, j);
        pair<int, int> t2 = find(dsu, a, b);
        
        if(t1 == t2) return;
        if(sz[t1.first][t1.second] >= sz[t2.first][t2.second]){
            dsu[t2.first][t2.second] = t1;
            sz[t1.first][t1.second] += sz[t2.first][t2.second];
        }
        else{
            dsu[t1.first][t1.second] = t2;
            sz[t2.first][t2.second] += sz[t1.first][t1.second];
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<pair<int, int>>> dsu(m, vector<pair<int, int>>(n));
        vector<vector<int>> sz(m, vector<int>(n, 1));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dsu[i][j] = {i, j};
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    for(int k = 0; k < 4; k++){
                        if(isvalid(m, n, i + dx[k], j + dy[k]) && grid[i + dx[k]][j + dy[k]] == 1){
                            uni(dsu, sz, i, j, i + dx[k], j + dy[k]);
                        }
                    }
                }
            }
        }
        
        int ans = 0, curr;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, sz[i][j]);        
            }
        }
        
        set<pair<int, int>> tmp;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    for(int k = 0; k < 4; k++){
                        if(isvalid(m, n, i + dx[k], j + dy[k]) && grid[i + dx[k]][j + dy[k]] == 1){
                            tmp.insert(find(dsu, i + dx[k], j + dy[k]));   
                        }
                    }
                    
                    curr = 1;
                    for(auto k : tmp){
                        curr += sz[k.first][k.second];    
                    }
                    
                    ans = max(ans, curr);
                    tmp.clear();
                }
            }
        }
        
        return ans;
    }
};