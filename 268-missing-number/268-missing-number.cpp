class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int c = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            c ^= i;
            c ^= nums[i];
        }
        c ^= n;
        return c;
    }
};