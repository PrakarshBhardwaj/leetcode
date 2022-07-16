class Solution {
public:
    const int M = 1e9 + 7;
    
    long long go(int a, long long b){
        long long ans = 1;
        
        while(b){
            if(b&1) ans = (ans * a) % M;
            a = ((long long)a * a) % M;
            b >>= 1;
        }
        
        return ans;
    }
    
    int countGoodNumbers(long long n) {
        long long ev = n/2 + (n&1);
        long long odd = n/2;
        
        return ( go(4, odd) * go(5, ev) ) % M;
    }
};