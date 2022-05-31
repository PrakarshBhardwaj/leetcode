class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if(k > n) return false;
        
        int ch = 0;
        
        for(int i = 0; i < k; i++){
            ch <<= 1;
            ch = ch | (int)(s[i] == '1');
        }
        
        unordered_set<int> ss;
        ss.insert(ch);
        int p = pow(2, k) - 1;
        
        for(int i = k; i < n; i++){
            ch <<= 1;
            // cout << ch << " ";
            ch = ch | (int)(s[i] == '1');
            // cout << ch << " ";
            ch &= p;
            // cout << ch << endl;
            ss.insert(ch);
        }
        
        return (ss.size() == p + 1);
    }
};