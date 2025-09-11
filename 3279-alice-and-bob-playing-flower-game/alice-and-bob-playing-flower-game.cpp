class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            long long x = i;
            if (x % 2 != 0) {
                ans += m / 2;
            } else {
                ans += (m + 1) / 2;
            }
        }
        return ans;
    }
};