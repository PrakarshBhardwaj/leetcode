class Solution {
public:
    unordered_set<int> ss;
    const int inf = 1e9 + 7;
    
    void go(string &tiles, int &n, int chash, int curr){
        ss.insert(chash);
        
        for(int i = curr; i < n; i++){
            swap(tiles[curr], tiles[i]);
            go(tiles, n, ( (long long)33 * chash + (int)(tiles[curr] - 'A' + 1)) % inf, curr + 1);
            swap(tiles[curr], tiles[i]);
        }
    }
    
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        go(tiles, n, 0, 0);
        return ss.size() - 1;
    }
};