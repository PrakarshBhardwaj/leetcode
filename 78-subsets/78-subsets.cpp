class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        int e = (1<<n);
        
        for(int i = 0; i < e; i++){
            vector<int> tmp;
            
            for(int j = 0; j < n; j++){
                if(i & (1<<j)) tmp.push_back(nums[j]);
            }
            
            ans.push_back(tmp);
        }
        
        return ans;
    }
};