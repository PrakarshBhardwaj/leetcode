class Node{
    public:
    bool isend = false;
    unordered_map<char, Node*> mp;
};

class Trie{
    public:
    Node *root;
    
    Trie(){
        root = new Node();
    }
    
    void insert(string &word){
        insertgo(word, root, 0);
        return;
    }
    
    void insertgo(string &word, Node *root, int i){
        if(i >= word.length()){
            root->isend = true;
            return;
        }
        
        if(root->mp.find(word[i]) == root->mp.end()){
            root->mp[word[i]] = new Node();
        }
        
        insertgo(word, root->mp[word[i]], i + 1);
        return;
    }
    
    bool find(string &word){
        return findgo(word, root, 0);
    }
    
    bool findgo(string &word, Node *root, int i){
        if(i >= word.length()) return root->isend;
        if(root->mp.find(word[i]) == root->mp.end()) return false;
        return findgo(word, root->mp[word[i]], i + 1);
    }
};

class Encrypter {
public:
    unordered_map<char, int> mp1;
    multimap<string, char> mp2;
    vector<string> values;
    vector<char> keys;
    Trie *tt;
    const int M = 1e9 + 7;

    Encrypter(vector<char>& k, vector<string>& vals, vector<string>& dict) {
        keys = k;
        values = vals;
        int n = keys.size();
        
        for(int i = 0; i < n; i++){
            mp1[keys[i]] = i;
            mp2.insert({values[i], keys[i]});
        }
        
        int n2 = dict.size();
        tt = new Trie();
        
        for(int i = 0; i < n2; i++){
            tt->insert(dict[i]);
        }
    }
    
    string encrypt(string word1) {
        int n = word1.size();
        string tmp;

        for(int i = 0; i < n; i++){
            if(mp1.find(word1[i]) == mp1.end()) return "";
            tmp += values[mp1[word1[i]]];
        }

        return tmp;
    }

    int go(string &word, Node *root, int i){
        if(i >= word.length()) return root->isend;
        
        auto itr = root->mp.begin();
        string tmp;
        tmp += word[i];
        tmp += word[i + 1];
        
        int cnt = 0;
        //cout << i << " ";
        for(; itr != root->mp.end(); itr++){
            //cout << itr->first << " ";
            if(mp1.find(itr->first) != mp1.end() && values[mp1[itr->first]] == tmp){
                //cout << values[mp1[itr->first]] << endl;
                cnt += go(word, itr->second, i + 2);        
            }    
        }
        
        return cnt;
    }
    
    int decrypt(string word2) {
        // string b = "bbb";
        // cout << tt->find(b);
        return go(word2, tt->root, 0);
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */