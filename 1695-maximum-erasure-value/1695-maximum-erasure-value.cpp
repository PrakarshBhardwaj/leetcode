class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> pref(n);
        pref[0] = nums[0];
        
        for(int i = 1; i < n; i++) pref[i] = pref[i - 1] + nums[i];
        
        unordered_map<int, int> mp;
        int curr = 0;
        int cl = 0;
        
        for(int i = 0; i < n; i++){
            if(mp.find(nums[i]) == mp.end() || mp[nums[i]] < cl){
                curr += nums[i];
                mp[nums[i]] = i;
            }
            else{
                ans = max(ans, curr);
                curr = pref[i] - pref[mp[nums[i]]];
                cl = mp[nums[i]] + 1;
                mp[nums[i]] = i;
            }
        }
        
        ans = max(ans, curr);
        
        return ans;
    }
};