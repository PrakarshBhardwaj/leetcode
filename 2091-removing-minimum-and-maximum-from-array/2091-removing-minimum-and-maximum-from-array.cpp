class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        auto itr = min_element(nums.begin(), nums.end());
        auto itr2 = max_element(nums.begin(), nums.end());
        int n1 = distance(nums.begin(), itr) + 1;
        int n2 = distance(nums.begin(), itr2) + 1;
        
        if(n1 < n2){
            n2 = n - n2 + 1;
        }
        else n1 = n - n1 + 1;
        
        int n3 = n - n1 - n2 + 1;
        
        return min(n1 + n2, min(n1 + n3, n2 + n3));
    }
};