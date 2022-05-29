class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> v(n, 0);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < words[i].length(); j++){
                int t = (int)(words[i][j] - 'a');
                v[i] |= (1<<t);
            }
        }
        int mx = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if( (v[i]&v[j]) == 0){
                    int l1 = words[i].length();
                    int l2 = words[j].length();
                    mx = max(mx, l1 * l2);
                }
            }
        }
        
        return mx;
    }
};