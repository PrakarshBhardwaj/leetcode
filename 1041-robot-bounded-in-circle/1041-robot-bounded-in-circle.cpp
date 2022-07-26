class Solution {
public:
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    
    bool isRobotBounded(string s) {
        int n = s.length();
        int t = 0, x = 0, y = 0;
        
        for(int i = 0; i < 4; i++){
            for(int i = 0; i < n; i++){
                if(s[i] == 'G'){
                    x += dx[t];
                    y += dy[t];
                }
                else if(s[i] == 'L') t = (t + 1) % 4;
                else t = (t - 1 + 4) % 4;
            }

            if(x == 0 && y == 0) return true;
        }
        
        return false;
    }
};