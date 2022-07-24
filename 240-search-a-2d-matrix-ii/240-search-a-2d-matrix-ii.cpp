class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        
        for(int i = 0; i < m; i++){
            auto itr = lower_bound(matrix[i].begin(), matrix[i].end(), target);
            if(itr != matrix[i].end() && *itr == target) return true;
        }
        
        return false;
    }
};