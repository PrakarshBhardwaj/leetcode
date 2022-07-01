class Solution {
public:
    int maximumUnits(vector<vector<int>>& bt, int ts) {
        int n = bt.size();
        
        sort(bt.begin(), bt.end(), [](vector<int> &v1, vector<int> &v2){
            return v1[1] >= v2[1];
        });
        
        int cs = 0;
        
        for(int i = 0; i < n; i++){
            int t = min(ts, bt[i][0]);
            cs += t*bt[i][1];
            ts -= t;
        }
        
        return cs;
    }
};