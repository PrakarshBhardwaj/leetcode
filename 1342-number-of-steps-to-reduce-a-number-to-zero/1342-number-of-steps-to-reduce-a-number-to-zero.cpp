const int N = 1e6 + 1;
static vector<int> V(N, -1);

class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0) return 0;
        if(V[num] != -1) return V[num];
        
        if(num&1) return V[num] = numberOfSteps(num - 1) + 1;
        return V[num] = numberOfSteps(num/2) + 1;
    }
};