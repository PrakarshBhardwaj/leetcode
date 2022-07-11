class Solution {
public:
    int find(vector<int> &dsu, int c){
        if(dsu[c] == c) return c;
        return dsu[c] = find(dsu, dsu[c]);
    }
    
    bool uni(vector<int> &dsu, int a, int b){
        if(find(dsu, a) == find(dsu, b)) return false;
        dsu[find(dsu, b)] = find(dsu, a);
        return true;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> dsu(n);
        iota(dsu.begin(), dsu.end(), 0);
        
        for(int i = 0; i < n; i++){
            if(!uni(dsu, edges[i][0] - 1, edges[i][1] - 1)){
                return edges[i];
            }
        }
        
        return {};
    }
};