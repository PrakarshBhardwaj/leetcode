class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }
    
    bool isGoodArray(vector<int>& nums) {
        int n = nums.size();
        int tmp = 0;
        for(int i = 0; i < n; i++) tmp = gcd(tmp, nums[i]);
        
        return (tmp == 1);
    }
};