class Solution {
public:
    int n;
    int mod = 1e9 + 7;
    vector<int> dp;
    int solve(int start, string &s, int &k) {
        if (start >= n) {
            return 1;
        }
        if (dp[start] != -1) {
            return dp[start];
        }
        if (s[start] == '0') {
            return dp[start] =0;
        }
        long long num = 0;
        long long ans = 0;
        for (int i = start; i < n; i++) {
            num = (num * 10) + (s[i] - '0');
            if (num > k) {
                break;
            }
            ans =(ans%mod +  solve(i + 1, s, k)%mod)%mod;
        }
        return dp[start] = ans % mod;
    }
    int numberOfArrays(string s, int k) {
        n = s.size();
        dp.clear();
        dp.resize(n, -1);
        return (solve(0, s, k)) % mod;
    }
};