class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, s, dp);
    }

    int solve(int i, int j, const string& s, vector<vector<int>>& dp) {
        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        char first = s[i];
        int answer = 1 + solve(i + 1, j, s, dp);
        for (int k = i + 1; k <= j; k++) {
            if (s[k] == first) {
                int betterAnswer =
                    solve(i, k - 1, s, dp) + solve(k + 1, j, s, dp);
                answer = min(answer, betterAnswer);
            }
        }
        return dp[i][j] = answer;
    }
};