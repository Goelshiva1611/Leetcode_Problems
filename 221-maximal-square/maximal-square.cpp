class Solution {
public:
    int m;
    int n;
    vector<vector<int>> dp;
    int solve(vector<vector<char>>& matrix, int i, int j) {
        if (i >= m || j >= n) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (matrix[i][j] == '0') {
            return 0;
        }
        int down = solve(matrix, i + 1, j);
        int right = solve(matrix, i, j + 1);
        int diagonal = solve(matrix, i + 1, j + 1);

        return dp[i][j] = min({down, right, diagonal}) + 1;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int ma = 0;
        m = matrix.size();
        n = matrix[0].size();
        dp.resize(301, vector<int>(301, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    ma = max(ma, solve(matrix, i, j));
                }
            }
        }
        return ma * ma;
    }
};