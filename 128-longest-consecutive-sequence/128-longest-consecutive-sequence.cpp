class Solution {
public:
    int find(unordered_map<int, int> &mp, int curr){
        if(mp[curr] == curr){
            return curr;
        }
        return mp[curr] = find(mp, mp[curr]);
    }
    
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(mp.find(nums[i]) == mp.end()){
                if(mp.find(nums[i] - 1) != mp.end()){
                    mp[nums[i]] = nums[i] - 1;
                }
                else{
                    mp[nums[i]] = nums[i];
                }
                
                if(mp.find(nums[i] + 1) != mp.end()){
                    mp[nums[i] + 1] = nums[i];
                }
            }
        }
        
        int ans = 0;
        unordered_map<int, int> tmp;
        
        for(auto i : mp){
            tmp[find(mp, i.first)]++;
        }
        
        for(auto i : tmp){
            ans = max(ans, i.second);
        }
        
        return ans;
    }
};