class Solution {
public:
    class UNF{
        public:
        vector<int> dsu;
        
        UNF(int n){
            dsu = vector<int>(n);
            iota(dsu.begin(), dsu.end(), 0);
        }
        
        int find(int c){
            if(dsu[c] == c) return c;
            return dsu[c] = find(dsu[c]);
        }
        
        void uni(int a, int b){
            int tmp1 = find(a);
            int tmp2 = find(b);
            if(tmp1 == tmp2) return;
            dsu[tmp2] = tmp1;
        }
    };
    
    int findCircleNum(vector<vector<int>>& nums) {
        int n = nums.size();
        UNF *d = new UNF(n);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(nums[i][j]){
                    d->uni(i, j);
                }
            }
        }
        
        unordered_set<int> ss;
        
        for(int i = 0; i < n; i++){
            int tmp = d->find(i);
            ss.insert(tmp);
        }
        
        return ss.size();
    }
};