class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        int n = arr.size();
        vector<int> pref(n);
        pref[0] = arr[0];
        
        for(int i = 1; i < n; i++) pref[i] = arr[i] ^ pref[i - 1];
        
        int n2 = q.size();
        vector<int> ans(n2);
        
        for(int i = 0; i < n2; i++){
            if(q[i][0] > 0) ans[i] = pref[q[i][1]] ^ pref[q[i][0] - 1];
            else ans[i] = pref[q[i][1]];
        }
        
        return ans;
    }
};