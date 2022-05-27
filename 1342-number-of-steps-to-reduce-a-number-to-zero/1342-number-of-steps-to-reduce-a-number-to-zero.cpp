

class Solution {
public:
    int numberOfSteps(int num) {
        ios_base::sync_with_stdio(0);
        cin.tie(0), cout.tie(0);
        int cnt = 0;
        while(num) {
            if(num & 1) num -= 1;
            else num /= 2;
            cnt++;
        }
        return cnt;
    }
};