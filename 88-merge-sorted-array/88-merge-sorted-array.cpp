class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l=0,r=0;
        vector<int> ans(m+n);
        int i = 0;
        while(l < m && r < n){
            if(nums1[l] <= nums2[r]){
                ans[i] = nums1[l];
                l++;
            }
            else{
                ans[i] = nums2[r];
                r++;
            }
            i++;
        }
        while(l < m){
            ans[i] = nums1[l];
            l++, i++;
        }
        while(r < n){
            ans[i] = nums2[r];
            r++, i++;
        }
        nums1 = ans;
    }
};