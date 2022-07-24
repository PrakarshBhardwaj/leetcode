class Solution {
public:
    const int M = 1e9 + 7;
    
    int binmult(int a, int b){
        int ans = 0;
        while(b){
            if(b&1) ans += a;
            a += a;
            ans %= M;
            a %= M;
            b >>= 1;
        }
        return ans;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsr(n), nsl(n);
        stack<int> st;
        
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(st.empty()) nsr[i] = n;
            else nsr[i] = st.top(); 
            st.push(i);
        }
        
        st = stack<int>();
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) nsl[i] = -1;
            else nsl[i] = st.top(); 
            st.push(i);
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            ans += binmult(arr[i], ( (i - (nsl[i] + 1) + 1) * ((nsr[i] - 1) - i + 1) ));
            ans %= M;
        }
        
        return ans;
    }
};