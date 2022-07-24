class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(s.find(nums[i]) != s.end()){
                s.erase(nums[i]);
            }
            else s.insert(nums[i]);
        }
        
        int t1 = s.size();
        int t2 = (n - t1)/2;
        
        return {t2, t1};
    }
};