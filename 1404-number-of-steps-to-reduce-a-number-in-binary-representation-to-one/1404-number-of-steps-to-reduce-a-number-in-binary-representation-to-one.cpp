class Solution {
public:
    int numSteps(string s) {
        int n = s.length();
        int steps = 0;
        
        for(int i = n - 1; i >= 0; i--){
            if(i == 0 && s[i] == '1') break;
            
            if(s[i] == '1'){
                int j = i;
                while(j >= 0 && s[j] == '1'){
                    s[j] = '0';
                    j--;
                }
                if(j >= 0) s[j] = '1';
                steps++;
            }
            
            if(s[i] == '0') steps++;
        }
        
        return steps;
    }
};