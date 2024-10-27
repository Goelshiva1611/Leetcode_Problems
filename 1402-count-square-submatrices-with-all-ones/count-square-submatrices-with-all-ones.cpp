class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& matrix, int i, int j, int m, int n) {
        if (i >= m || j >= n)
            return 0;
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (matrix[i][j] == 0)
            return 0;
        int down = solve(matrix, i + 1, j, m, n);
        int right = solve(matrix, i, j + 1, m, n);
        int diagonal = solve(matrix, i + 1, j + 1, m, n);
        return dp[i][j] = 1 + min({down, right, diagonal});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = 0;
        dp.resize(301, vector<int>(301, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1)
                    count += solve(matrix, i, j, m, n);
            }
        }
        return count;
    }
};