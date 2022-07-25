class Solution {
public:
    int go(string &ring, string &key, int c, int i, vector<vector<int>> &dp, unordered_map<char, vector<int>> &mp){
        int n1 = ring.length(), n2 = key.length();
        if(c >= n2) return 0;
        if(dp[i][c] != -1) return dp[i][c];
        
        int ans = INT_MAX;
        
        for(auto k : mp[key[c]]){
            ans = min(ans, min(abs(k - i), n1 - abs(k - i)) + go(ring, key, c + 1, k, dp, mp) + 1);
        }
        
        return dp[i][c] = ans;
    }
    
    int findRotateSteps(string ring, string key) {
        int n1 = ring.length(), n2 = key.length();
        unordered_map<char, vector<int>> mp;
        
        for(int i = 0; i < n1; i++){
            mp[ring[i]].push_back(i);
        }
        
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        
        return go(ring, key, 0, 0, dp, mp);
    }
};