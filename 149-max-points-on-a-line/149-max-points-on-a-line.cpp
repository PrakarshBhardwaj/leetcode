class Solution {
public:
    const int M = 1e9 + 7;
    
    int hhash(int x, int y){
        return ((23 * x) % M) + ((33 * y) % M);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        if(n == 1) return 1;
        
        unordered_map<int, int> mp;
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            mp.clear();
            for(int j = i + 1; j < n; j++){
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = __gcd(dx, dy);
                dx /= g;
                dy /= g;
                int ch = hhash(dx, dy);
                mp[ch]++;
                ans = max(ans, mp[ch] + 1);
            }
        }
        
        return ans;
    }
};