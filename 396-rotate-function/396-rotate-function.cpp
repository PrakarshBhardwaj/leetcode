class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        
        for(int i = 0; i < n; i++) s += nums[i];
        
        int curr = 0;
        
        for(int i = 0; i < n; i++) curr += i*nums[i];
        int ans = curr;
        
        for(int i = 1; i < n; i++){
            curr = curr - (s - nums[i - 1]) + (n - 1)*nums[i - 1];
            ans = max(ans, curr);
        }
        
        return ans;
    }
};