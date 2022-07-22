class Solution {
public:
    bool go(unordered_map<char, int> &mp, unordered_set<char> &vow){
        for(auto c : vow) if(mp[c] == 0) return false;
        return true;
    }
    
    int countVowelSubstrings(string word) {
        int n = word.length();
        int ans = 0;
        unordered_set<char> vow = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> mp;
        int idx = -1;
        int l = 0;
        
        for(int i = 0; i < n; i++){
            if(vow.find(word[i]) != vow.end()){
                mp[word[i]]++;
                
                if(go(mp, vow)){
                    while(mp[word[l]] - 1 > 0){
                        mp[word[l]]--;
                        l++;
                    }
                    ans += l - idx;   
                }
            }
            else{
                idx = i;
                l = i + 1;
                mp.clear();
            }
        }
        
        return ans;
    }
};