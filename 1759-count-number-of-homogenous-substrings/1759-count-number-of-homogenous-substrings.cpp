class Solution {
public:
    const int M = 1e9 + 7;
    
    int countHomogenous(string s) {
        int n = s.length();
        int l = 0, r = 0;
        int cnt = 0;
        
        while(r < n){
            if(s[l] != s[r]){
                l = r;
            }   
            cnt += (r - l + 1);
            cnt %= M;
            r++;
        }
        
        return cnt;
    }
};