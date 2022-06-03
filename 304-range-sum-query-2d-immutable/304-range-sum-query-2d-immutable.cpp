class NumMatrix {
public:
    vector<vector<int>> pref;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        pref = vector<vector<int>>(m, vector<int>(n));
        
        pref[0][0] = matrix[0][0];
        
        for(int i = 1; i < m; i++){
            pref[i][0] = pref[i - 1][0] + matrix[i][0];
        }
        for(int i = 1; i < n; i++){
            pref[0][i] = pref[0][i - 1] + matrix[0][i];
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int tot = pref[row2][col2];
        int to_sub = 0;
        
        if(row1 - 1 >= 0 && col1 - 1 >= 0) to_sub -= pref[row1 - 1][col1 - 1];
        if(row1 - 1 >= 0) to_sub += pref[row1 - 1][col2];
        if(col1 - 1 >= 0) to_sub += pref[row2][col1 - 1];
        
        return tot - to_sub;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */