class Solution {
public:
    bool go(string &s1, string &s2, string &s3, int n1, int n2, int n3, vector<vector<vector<int>>> &dp){
        if(n3 < 0) return dp[n3 + 1][n2 + 1][n1 + 1] = ((n1 < 0) && (n2 < 0));
        
        if(dp[n3 + 1][n2 + 1][n1 + 1] != -1) return dp[n3 + 1][n2 + 1][n1 + 1];
        
        bool ans = false;
        if(n1 >= 0 && s1[n1] == s3[n3]) ans |= go(s1, s2, s3, n1 - 1, n2, n3 - 1, dp);
        if(n2 >= 0 && s2[n2] == s3[n3]) ans |= go(s1, s2, s3, n1, n2 - 1, n3 - 1, dp);
        
        return dp[n3 + 1][n2 + 1][n1 + 1] = ans;
    }
    
    bool goSpaceOptimized(string &s1, string &s2, string &s3, int n1, int n2, int n3, vector<vector<int>> &dp){
        // n3 will always be n1 + n2, so 3rd state of dp is dependent on 2nd and 1st state
        // thus, it can be reduced to a 2d dp as n1 and n2 are the only 2 real states
        if(n3 < 0) return dp[n2 + 1][n1 + 1] = ((n1 < 0) && (n2 < 0));
        
        if(dp[n2 + 1][n1 + 1] != -1) return dp[n2 + 1][n1 + 1];
        
        bool ans = false;
        if(n1 >= 0 && s1[n1] == s3[n3]) ans |= goSpaceOptimized(s1, s2, s3, n1 - 1, n2, n3 - 1, dp);
        if(n2 >= 0 && s2[n2] == s3[n3]) ans |= goSpaceOptimized(s1, s2, s3, n1, n2 - 1, n3 - 1, dp);
        
        return dp[n2 + 1][n1 + 1] = ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        
        // vector<vector<vector<int>>> dp(n3 + 1, vector<vector<int>>(n2 + 1, vector<int>(n1 + 1, -1)));
        // return go(s1, s2, s3, n1 - 1, n2 - 1, n3 - 1, dp);
        
        // space optimized 
        vector<vector<int>> dp(n2 + 1, vector<int>(n1 + 1, -1));
        return goSpaceOptimized(s1, s2, s3, n1 - 1, n2 - 1, n3 - 1, dp);
    }
};