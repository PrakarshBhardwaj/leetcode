class Solution {
public:
    const int M = 1e9 + 7;
    unordered_map<int, unordered_map<bool, int>> dp;
    
    int go(long long n, bool flg){
        if(n == 1) return (flg ? 4 : 5);
        if(dp.find(n) != dp.end() && dp[n].find(flg) != dp[n].end()) return dp[n][flg];
        
        int tmp = ((long long)go(n/2, !flg) * go(n/2, flg)) % M;
        if(n&1) tmp = ((long long)tmp * (flg ? 4 : 5)) % M;
        return dp[n][flg] = tmp;
    }
    
    int countGoodNumbers(long long n) {
        return go(n, false);
    }
};