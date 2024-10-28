class Solution {
public:
    int n = 0;
    int mod = 1e9 + 7;
    vector<vector<long long>> dp;
    int solve(int j, int stp) {
        if (j < 0 || j >= n)
            return 0;

        if (stp == 0) {
            if (j == 0)
                return 1;
            else
                return 0;
        }

        if (dp[j][stp] != -1)
            return dp[j][stp];

        long long left = 0;
        long long right = 0;
        stp -= 1;
        if (j > 0)
            left = solve(j - 1, stp);
        if (j < n - 1)
            right = solve(j + 1, stp);

        long long stay = solve(j, stp);
        stp+=1;
        return dp[j][stp] = (left + right + stay) % mod;
    }
    int numWays(int steps, int arrLen) {
        n = arrLen;
        dp.resize(501, vector<long long>(501, -1));
        return solve(0, steps);
    }
};