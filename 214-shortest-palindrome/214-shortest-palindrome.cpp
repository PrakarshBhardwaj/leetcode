class Solution {
public:
    int b = 33;
    int M = 1e9 + 7;
    
    int gcdExtended(int a, int b, int *x, int *y)
    {
        if (a == 0)
        {
            *x = 0, *y = 1;
            return b;
        }

        int x1, y1;
        int gcd = gcdExtended(b%a, a, &x1, &y1);

        *x = y1 - (b/a) * x1;
        *y = x1;

        return gcd;
    }
 
    int modInverse(int b, int m)
    {
        int x, y;
        int g = gcdExtended(b, m, &x, &y);

        if (g != 1)
            return -1;

        return (x%m + m) % m;
    }
 
    int modDivide(int a, int b, int m)
    {
        a = a % m;
        int inv = modInverse(b, m);
        return ((long long)inv * a) % m;
    }
    
    int binmult(int a, int b){
        int ans = 0;
        while(b){
            if(b&1) ans += a;
            a += a;
            b >>= 1;
            a %= M;
            ans %= M;
        }
        return ans;
    }
    
    int binpow(int a, int b){
        int ans = 1;
        while(b){
            if(b&1) ans = binmult(ans, a);
            a = ((long long)a * a) % M;
            b >>= 1;
        }
        return ans;
    }
    
    void hhash(int &chash, char X, int p){
        chash = (chash + binmult((X - 'a' + 1), binpow(b, p))) % M;
        return;
    }
    
    void rhash(int &chash, char X){
        chash = ((long long)chash - (X - 'a' + 1) + M) % M;
        chash = modDivide(chash, b, M);
        return;
    }
    
    string shortestPalindrome(string s) {
        int n = s.length();
        if(n == 0) return s;
        int chash = 0;
        vector<int> v(n);
        
        for(int i = 0; i < n; i++){
            hhash(chash, s[i], i);
            v[i] = chash;
        }
        
        chash = 0;
        
        for(int i = n - 1; i >= 0; i--) hhash(chash, s[i], n - 1 - i);
        if(chash == v[n - 1]) return s;
        
        int e;
        for(int i = n - 2; i >= 0; i--){
            rhash(chash, s[i + 1]);
            if(chash == v[i]){
                e = i;
                break;
            }
        }
        
        string ans;
        for(int i = e + 1; i < n; i++){
            ans = s[i] + ans;
        }
        ans += s;
        return ans;
    }
};