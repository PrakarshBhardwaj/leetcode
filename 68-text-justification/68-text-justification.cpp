class Solution {
public:
    int cnt_words(string &tmp){
        int cnt = 0;
        int n = tmp.length();
        bool flg = false;
        
        for(int i = 0; i < n; i++){
            if(tmp[i] != ' '){
                flg = true;
                continue;
            }
            else{
                cnt++;
                flg = false;
            }
        }
        
        cnt += flg;
        return cnt;
    }
    
    string fixline(string &tmp, int mx){
        string tmp2;
        int wcnt = cnt_words(tmp), gap, rem;
        
        if(wcnt == 1){
            gap = mx - tmp.length();
            tmp2 = tmp;
            while(tmp2.length() < mx) tmp2 += " ";
            
            return tmp2;
        }
        else{
            gap = (mx - tmp.length())/ (wcnt - 1);
            rem = (mx - tmp.length()) % (wcnt - 1);
        }
        
        // cout << wcnt << " " << gap << " " << rem << " ";
        
        for(int i = 0; i < tmp.length(); i++){
            tmp2 += tmp[i];
            
            if(tmp[i] == ' '){
                for(int j = 0; j < gap; j++) tmp2 += " ";
                
                if(rem > 0){
                    tmp2 += " ";
                    rem--;
                }
            }
        }
        
        return tmp2;
    }
    
    vector<string> fullJustify(vector<string>& w, int mx) {
        vector<string> ans;
        string tmp = w[0];
        int n = w.size();
        
        for(int i = 1; i < n; i++){
            if(tmp.length() + 1 + w[i].length() > mx){
                // cout << endl << tmp << " ";
                ans.push_back(fixline(tmp, mx));
                tmp = w[i];
            }
            else{
                tmp += " " + w[i];
            }
        }
        
        while(tmp.length() < mx) tmp += " ";
        ans.push_back(tmp);
        
        return ans;
    }
};