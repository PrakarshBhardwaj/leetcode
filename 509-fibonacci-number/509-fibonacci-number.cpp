class Solution {
public:
    /*
    int fib(int n) {
        // O(n)
        if(n == 0 || n == 1) return n;
        
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i - 2];
        }
        
        return dp[n];
    }
    */
    vector<vector<int>> A = {{1, 1},
                             {1, 0}};
    vector<vector<int>> BASE = {{1}, 
                                {0}};
    vector<vector<int>> I = {{1, 0},
                             {0, 1}};
    
    vector<vector<int>> mult(vector<vector<int>> &A, vector<vector<int>> &B){
        int r = A.size();
        int n = A[0].size();
        int c = B[0].size();
        
        vector<vector<int>> res(r, vector<int>(c, 0));
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                for(int k = 0; k < n; k++){
                    res[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        
        return res;
    }
    
    vector<vector<int>> powr(vector<vector<int>> &A, int p){
        if(p == 0) return I;
        if(p == 1) return A;
        
        vector<vector<int>> tmp = powr(A, p/2);
        tmp = mult(tmp, tmp);
        if(p&1) return mult(tmp, A);
        else return tmp;
    }
    
    int fib(int n) {
        // using matrix exponentition
        // k^3 * log(n)
        if(n == 0) return 0;
        
        vector<vector<int>> tmp = powr(A, n-1);
        vector<vector<int>> ans = mult(tmp, BASE);
        return ans[0][0];
    }
};