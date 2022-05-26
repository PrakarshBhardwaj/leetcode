class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        
        int c1 = 0, c2 = 0;
        for(int i = 0; i < n1; i++){
            c1 ^= arr1[i];
        }
        for(int i = 0; i < n2; i++){
            c2 ^= arr2[i];
        }
        
        return (c1 & c2);
    }
};