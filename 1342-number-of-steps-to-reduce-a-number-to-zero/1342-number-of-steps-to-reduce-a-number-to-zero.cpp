const int N = 1e6 + 1;
static vector<int> V(N, -1);

class Solution {
public:
    int go(int num){
        if(num == 0) return 0;
        if(V[num] != -1) return V[num];
        
        if(num&1) return V[num] = go(num - 1) + 1;
        return V[num] = go(num/2) + 1;
    }
    
    int numberOfSteps(int num) {
        ios_base::sync_with_stdio(0);
        return go(num);
    }
};