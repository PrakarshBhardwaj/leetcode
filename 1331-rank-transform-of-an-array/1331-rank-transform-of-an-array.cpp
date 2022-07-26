class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> tmp(arr.begin(), arr.end());
        sort(tmp.begin(), tmp.end());
        auto ip = unique(tmp.begin(), tmp.end());
        
        for(int i = 0; i < n; i++){
            auto itr = lower_bound(tmp.begin(), ip, arr[i]);
            arr[i] = distance(tmp.begin(), itr) + 1;
        }
        
        return arr;
    }
};