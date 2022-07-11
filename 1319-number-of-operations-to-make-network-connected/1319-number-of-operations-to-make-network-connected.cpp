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
    
    int makeConnected(int n, vector<vector<int>>& conn) {
        vector<int> dsu(n);
        iota(dsu.begin(), dsu.end(), 0);
        int red = 0;
        
        for(int i = 0; i < conn.size(); i++){
            if(!uni(dsu, conn[i][0], conn[i][1])){
                red++;        
            }
        }
        
        unordered_set<int> ss;
        for(int i = 0; i < n; i++) ss.insert(find(dsu, i));
        
        return (ss.size() - 1 <= red ? ss.size() - 1 : -1);
    }
};