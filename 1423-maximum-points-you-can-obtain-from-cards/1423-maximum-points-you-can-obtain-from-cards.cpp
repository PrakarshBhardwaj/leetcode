class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int csum = 0;
        
        for(int i = 0; i < k; i++){
            csum += nums[i];    
        }
        
        ans = csum;
        
        for(int i = 0; i < k; i++){
            csum -= nums[k - 1 - i];
            csum += nums[n - 1 - i];
            ans = max(ans, csum);
        }
        
        return ans;
    }
};