class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> g(n);
        vector<int> deg(n, 0);
        
        for(int i = 0; i < p.size(); i++){
            g[p[i][1]].push_back(p[i][0]);
            deg[p[i][0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(deg[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            int tmp = q.front();
            ans.push_back(tmp);
            
            for(auto i : g[tmp]){
                deg[i]--;
                if(deg[i] == 0) q.push(i);
            }
            
            q.pop();
        }
        
        if(ans.size() == n) return ans;
        else return {};
    }
};