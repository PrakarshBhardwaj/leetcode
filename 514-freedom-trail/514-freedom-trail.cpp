class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n1 = ring.length(), n2 = key.length();
        unordered_map<char, vector<int>> mp;
        
        for(int i = 0; i < n1; i++){
            mp[ring[i]].push_back(i);
        }
        
        vector<vector<int>> dp(n1, vector<int>(n2));
        
        for(int j = 0; j < n1; j++){
            int tmp = INT_MAX;
            for(auto k : mp[key[n2 - 1]]){
                tmp = min(tmp, min(abs(k - j), n1 - abs(j - k)));
            }
            dp[j][n2 - 1] = tmp + 1;
        }
        
        for(int i = n2 - 2; i >= 0; i--){
            for(int j = 0; j < n1; j++){
                int tmp = INT_MAX;
                for(auto k : mp[key[i]]){
                    tmp = min(tmp, min(abs(j - k), n1 - abs(j - k)) + dp[k][i + 1]);
                }
                dp[j][i] = tmp + 1;
            }
        }
        
        return dp[0][0];
    }
};