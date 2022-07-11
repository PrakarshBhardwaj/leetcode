class Solution {
public:
    const int inf = 1e9 + 7;
    
    int go(vector<int> &nums, int curr, int k, int st, vector<vector<pair<int, int>>> &dp){
        int ans = 0;
        if(curr >= nums.size()) return 0;
        if(k <= 0 && st == 1) return 0;
        
        if(st == 1){
            // buy
            if(dp[curr][k].first != 0 - inf) return dp[curr][k].first;
            
            ans = max(ans, go(nums, curr + 1, k - 1, 2, dp) - nums[curr]);
            ans = max(ans, go(nums, curr + 1, k, 1, dp));
            
            return dp[curr][k].first = ans;
        }
        else{
            // sell
            if(dp[curr][k].second != 0 - inf) return dp[curr][k].second;
            
            ans = max(ans, go(nums, curr, k, 1, dp) + nums[curr]);
            ans = max(ans, go(nums, curr + 1, k, 2, dp));
            
            return dp[curr][k].second = ans;
        }
    }
    
    int maxProfit(int k, vector<int>& nums) {
        int curr = 0;
        int n = nums.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(k + 1, {-inf, -inf}));
        return go(nums, 0, k, 1, dp);
    }
};