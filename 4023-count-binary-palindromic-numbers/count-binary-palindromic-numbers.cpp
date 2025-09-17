class Solution {
public:
    int find(long long n) {
        int c = 0;
        while (n) {
            n = n / 2;
            c++;
        }
        return c;
    }
    int countBinaryPalindromes(long long n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 2;

        int L = find(n);
        vector<int> dp(L + 1, 0);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i <= L; i++) {
            dp[i] = 1 << ((i - 1) / 2);
        }
        int res = 0;
        for (int i = 1; i < L; i++)
            res += dp[i];
        res += construct(L - 2, 1, (1LL << (L - 1)) + 1, n);
        return res;
    }

private:
    int construct(int l, int r, long long cur, long long limit) {
        if (cur > limit)
            return 0;
        if (l < r)
            return 1;
        if (l == r) {
            int count = 1;
            if (cur + (1LL << l) <= limit)
                count++;
            return count;
        }
        int zeros = construct(l - 1, r + 1, cur, limit);
        int ones =
            construct(l - 1, r + 1, cur + (1LL << l) + (1LL << r), limit);
        return zeros + ones;
    }
};