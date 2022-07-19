class Solution {
public:
    struct cmp{
        bool operator()(pair<string, int> &p1, pair<string, int> &p2){
            if(p1.second == p2.second) return p1.first < p2.first;
            return p1.second > p2.second;
        }    
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int> mp;
        
        for(int i = 0; i < n; i++){
            mp[words[i]]++;
        }
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        
        for(auto &[m, n] : mp){
            pq.push({m, n});
            if(pq.size() > k) pq.pop();
        }
        
        vector<string> ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};