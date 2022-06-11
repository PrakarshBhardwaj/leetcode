class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> pref(n);
        vector<int> suff(n);
        
        pref[0] = nums[0];
        for(int i = 1; i < n; i++) pref[i] = pref[i - 1] + nums[i];
        
        suff[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) suff[i] = suff[i + 1] + nums[i];
        
        int ans = 1e9 + 7;
        
        for(int i = 0; i < n; i++){
            int l = i + 1, r = n - 1;
            
            if(pref[i] == x || suff[n - 1 - i] == x){
                ans = min(ans, i + 1);
                continue;
            }
            
            while(l <= r){
                int mid = l + (r - l)/2;
                
                if(suff[mid] + pref[i] == x){
                    ans = min(ans, i + 1 + (n - 1 - mid + 1));
                    break;
                }
                else if(suff[mid] + pref[i] < x){
                    r = mid - 1;
                }
                else l = mid + 1;
            }
        }
        
        return (ans == 1e9 + 7? -1 : ans);
    }
};