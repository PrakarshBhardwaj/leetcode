class Solution {
public:
    int ans = 0;
    
    void go(string &tiles, int &n, int curr){
        ans++;
        unordered_set<char> s;
        
        for(int i = curr; i < n; i++){
            if(s.find(tiles[i]) == s.end()){
                s.insert(tiles[i]);
                swap(tiles[curr], tiles[i]);
                go(tiles, n, curr + 1);
                swap(tiles[curr], tiles[i]);
            }
        }
    }
    
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        go(tiles, n, 0);
        return ans - 1;
    }
};