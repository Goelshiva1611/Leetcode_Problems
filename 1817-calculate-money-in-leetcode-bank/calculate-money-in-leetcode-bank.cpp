class Solution {
public:
    int t, p, ans = 0;
    int totalMoney(int n) {
        for (int i = 1; i <= n; i++) {
            if (i % 7 == 1) {
                p = t + 1;
                t++;
            }
            ans += p;
            p++;
        }
        return ans;
    }
};