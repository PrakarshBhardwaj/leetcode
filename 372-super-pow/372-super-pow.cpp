class Solution {
public:
    int binpow(int a, int b, int m){
        int ans = 1;
        while(b){
            if(b&1) ans *= a;
            a *= a;
            b >>= 1;
            ans %= m;
            a %= m;
        }
        return ans;
    }
    
    int superPow(int a, vector<int>& b) {
        int etf_1337 = 1140;
        int tmp = 0, n = b.size();
        
        for(int i = 0; i < n; i++){
            tmp = 10*tmp + b[i];
            tmp %= etf_1337;
        }
        
        return binpow(a%1337, tmp, 1337);
    }
};