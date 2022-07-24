class Solution {
public:
    int go(int n){
        int ans = 0;
        while(n){
            ans += n%10;
            n /= 10;
        }
        return ans;
    }
    
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> dig(n);
        
        for(int i = 0; i < n; i++) dig[i] = go(nums[i]);
        
        unordered_map<int, int> mp;
        int ans = -1;
        
        for(int i = 0; i < n; i++){
            if(mp.find(dig[i]) != mp.end()){
                ans = max(ans, nums[i] + mp[dig[i]]);
                mp[dig[i]] = max(mp[dig[i]], nums[i]);
            }
            else mp[dig[i]] = nums[i];
        }
        
        return ans;
    }
};