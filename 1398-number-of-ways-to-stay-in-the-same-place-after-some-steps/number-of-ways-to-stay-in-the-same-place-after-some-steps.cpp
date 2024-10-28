class Solution {
public:
    int mod = 1e9 + 7;
    int n;
    vector<vector<long long>> dp;
    
    int solve(int j, int stp) {
        if (j < 0 || j >= n) return 0;
        if (stp == 0) return j == 0 ? 1 : 0;

        if (dp[j][stp] != -1) return dp[j][stp];

        long long left = (j > 0) ? solve(j - 1, stp - 1) : 0;
        long long right = (j < n - 1) ? solve(j + 1, stp - 1) : 0;
        long long stay = solve(j, stp - 1);

        return dp[j][stp] = (left + right + stay) % mod;
    }
    
    int numWays(int steps, int arrLen) {
        n = min(arrLen, steps / 2 + 1); // optimize bounds
        dp.resize(n, vector<long long>(steps + 1, -1));
        return solve(0, steps);
    }
};
