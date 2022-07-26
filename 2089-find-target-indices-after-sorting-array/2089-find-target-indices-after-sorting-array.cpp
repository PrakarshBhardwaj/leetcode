class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int less = 0, eq = 0;
        
        for(int i = 0; i < n; i++){
            less += (nums[i] < target);
            eq += (nums[i] == target);
        }
        
        vector<int> ans(eq);
        iota(ans.begin(), ans.end(), less);
        return ans;
    }
};