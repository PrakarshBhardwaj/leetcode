class Solution {
public:
    struct Node{
      int val = -1;  
    };
    
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        unordered_map<char, Node> mp;
        int ans = 0, l;
        while(j < s.length()){
            if(mp[s[j]].val != -1){
                if(mp[s[j]].val < i){
                    mp[s[j]].val = j;
                    j++;
                    continue;
                }
                l = j - i;
                ans = max(ans, l);
                i = mp[s[j]].val + 1;
            }
            mp[s[j]].val = j;
            j++;
        }
        return max(ans, j - i);
    }
};