class Solution {
public:
    int go(vector<int> &nums, int k){
        int n = nums.size();
        int l  = 0, cnt = 0;
        map<int, int> mp;
        
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            
            if(mp.size() > k){
               while(1){
                    mp[nums[l]]--;
                    if(mp[nums[l]] == 0) break;
                    l++;
                }
                mp.erase(nums[l]);
                l++;
            }
            
            cnt += (i - l + 1);
        }
        
        return cnt;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return go(nums, k) - go(nums, k - 1);
    }
};