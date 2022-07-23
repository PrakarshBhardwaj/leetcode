class Solution {
public:
    const int M = 1e9 + 7;
    
    int numSub(string s) {
        int n = s.length();
        int ans = 0;
        int csum = 0;
        int l = 0;
        
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                l = i + 1;
                csum = 0;
                continue;
            }
            
            csum++;
            ans += csum;
            ans %= M;
        }
        
        return ans;
    }
};