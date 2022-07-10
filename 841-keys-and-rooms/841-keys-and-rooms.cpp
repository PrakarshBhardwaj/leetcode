class Solution {
public:
    void dfs(vector<vector<int>> &g, vector<bool> &vis, int curr, int &cnt){
        vis[curr] = true;
        cnt++;
        for(auto i : g[curr]){
            if(!vis[i]) dfs(g, vis, i, cnt);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int cnt = 0;
        int n = rooms.size();
        vector<bool> vis(n, false);
        
        dfs(rooms, vis, 0, cnt);
        return (cnt == n);
    }
};