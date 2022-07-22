class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, ans = 0;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++){
            mp[fruits[i]]++;
            
            if(mp.size() > 2){
                while(1){
                    mp[fruits[l]]--;
                    
                    if(mp[fruits[l]] == 0){
                        mp.erase(fruits[l]);
                        l++;
                        break;
                    }
                    
                    l++;
                }   
            }
            
            ans = max(ans, i - l + 1);
        }
        
        return ans;
    }
};