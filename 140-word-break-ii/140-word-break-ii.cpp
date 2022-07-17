class Solution {
public:
    vector<string> go(string &s, int strt, int end, unordered_set<string> &ss){
        if(strt >= end) return {};
        
        string tmp, tmp2;
        vector<string> ans, tt;
        tmp2 = s.substr(strt, end - strt);
        if(ss.find(tmp2) != ss.end()) ans.push_back(tmp2);
        
        for(int i = strt; i < end; i++){
            tmp += s[i];
            if(ss.find(tmp) != ss.end()){
                tt = go(s, i + 1, end, ss);
                for(int j = 0; j < tt.size(); j++){
                    tmp2 = tmp + " " + tt[j];
                    ans.push_back(tmp2);
                }
            }
        }
        
        return ans;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> ss(wordDict.begin(), wordDict.end());
        return go(s, 0, n, ss);
    }
};