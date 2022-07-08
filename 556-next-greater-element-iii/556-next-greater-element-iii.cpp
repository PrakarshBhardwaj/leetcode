class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> dig;
        
        while(n){
            dig.push_back(n%10);
            n /= 10;
        }
        
        reverse(dig.begin(), dig.end());
        int k = dig.size();
        
        int f = -1;
        
        for(int i = k - 2; i >= 0; i--){
            if(dig[i] < dig[i + 1]){
                f = i;
                break;
            }
        }
        
        if(f == -1) return -1;
        int s;
        
        int l = f + 1, r = k - 1;
        
        while(l <= r){
            int mid = l + (r - l)/2;
            
            if(dig[mid] > dig[f]){
                s = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        
        swap(dig[f], dig[s]);
        sort(dig.begin() + f + 1, dig.end());
        long ans = dig[0];
        
        for(int i = 1; i < k; i++){
            ans *= 10;
            ans += dig[i];
            if(ans > INT_MAX) return -1;
        }
        
        return (int)(ans);
    }
    
};