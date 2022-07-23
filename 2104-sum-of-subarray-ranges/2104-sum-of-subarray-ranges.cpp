class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int mn, mx;
        
        for(int i = 0; i < n; i++){
            mn = INT_MAX, mx = INT_MIN;
            for(int j = i; j < n; j++){
                mn = min(mn, nums[j]);
                mx = max(mx, nums[j]);
                ans += (mx - mn);
            }
        }
        
        return ans;
    }
};