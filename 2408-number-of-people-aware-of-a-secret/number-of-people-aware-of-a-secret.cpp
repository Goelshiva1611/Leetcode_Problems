class Solution {
public:
    int mod = 1e9 + 7;
    vector<int>dp;
    int solve(int day, int delay, int forget) {
        if (day == 1) {
            return 1;
        }
        if(dp[day]!=-1)
        {
            return dp[day];
        }
        int result = 0;
        for (int i = day - forget + 1; i <= day - delay; i++) {
            if (i > 0) {
                result = (result + solve(i, delay, forget)) % mod;
            }
        }
        return dp[day]=result;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int ans = 0;
        dp.resize(n+1,-1);
        for (int i = n - forget + 1; i <= n; i++) {
            if (i > 0) {
                ans = (ans + solve(i, delay, forget)) % mod;
            }
        }
        return ans;
    }
};