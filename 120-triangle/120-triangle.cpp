class Solution {
public:
    int minimumTotal(vector<vector<int>>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = nums[0][0];
        
        for(int i = 1; i < n; i++){
            dp[i][0] = dp[i - 1][0] + nums[i][0];
            
            for(int j = 1; j < i; j++){
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + nums[i][j];
            }    
            
            dp[i][i] = dp[i - 1][i - 1] + nums[i][i];
        }
        
        int ans = 1e9 + 7;
        
        for(int i = 0; i < n; i++){
            ans = min(ans, dp[n - 1][i]);
        }
        
        return ans;
    }
};