class Solution {
public:
    class TrieNode{
    public:
        unordered_map<char, TrieNode*> mp;
        bool isend;

        TrieNode(){
            isend = false;
        }
};

class Trie{
    public:
    TrieNode *root;
        Trie(){
            root = new TrieNode();
        }
        Trie(vector<string> &words){
            int n = words.size();
            root = new TrieNode();

            for(int i = 0; i < n; i++){
                insert(root, words[i], 0);
            }
        }

        void insert(TrieNode *curr, string &word, int n){
            if(n == word.size()){
                curr->isend = true;
                return;
            }
            if(curr->mp.find(word[n]) == curr->mp.end()){
                curr->mp[word[n]] = new TrieNode();
            } 

            insert(curr->mp[word[n]], word, n + 1);
        }

        bool find(string &word, int i, int j){
            return find_go(root, word, i, j);
        }

        bool find_go(TrieNode *curr, string &word, int n, int &j){
            if(n == j + 1) return curr->isend;
            // cout << word[n] << " ";
            if(curr->mp.find(word[n]) != curr->mp.end()){
                return find_go(curr->mp[word[n]], word, n + 1, j);
            }
            else return false;
        }
};
    
    bool go(string &s, Trie *t, int i, int j, vector<vector<int>> &dp){
        if(dp[i][j] != -1) return dp[i][j];

        if(t->find(s, i, j)) return true;
        if(i == j) return false;


        bool pre = false;

        for(int k = i; k < j && k - i + 1 <= 20; k++){
            pre |= (go(s, t, i, k, dp) && go(s, t, k + 1, j, dp));  
            if(pre) break;
        }

        return dp[i][j] = pre;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie *t = new Trie(wordDict);
        // cout << t->find(s, 0, 3);
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return go(s, t, 0, n - 1, dp);
        // return false;
    }
};