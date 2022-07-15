class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int cst = 0;
        
        int dx, dy;
        
        for(int i = 1; i < n; i++){
            dx = abs(points[i][0] - points[i - 1][0]);
            dy = abs(points[i][1] - points[i - 1][1]);
            cst += abs(dx - dy);
            cst += min(dx, dy);
        }
        
        return cst;
    }
};