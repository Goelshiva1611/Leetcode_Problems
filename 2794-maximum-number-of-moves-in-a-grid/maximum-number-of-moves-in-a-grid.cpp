class Solution {
public:
    int maxmove = 0;
    int n = 0;
    int m = 0;
    vector<vector<int>> dp;
    void solve(vector<vector<int>>& grid, int i, int j, int prev, int move) {
        if (i >= n || i < 0 || j >= m || j < 0) {
            return;
        }
        if (grid[i][j] <= prev) {
            return;
        }
        if (dp[i][j] != -1) {
            maxmove=max(dp[i][j],maxmove);
            dp[i][j]=maxmove;
            return;
        }
        solve(grid, i - 1, j + 1, grid[i][j], move + 1);
        solve(grid, i, j + 1, grid[i][j], move + 1);
        solve(grid, i + 1, j + 1, grid[i][j], move + 1);
        maxmove = max(maxmove, move);
        dp[i][j] = maxmove;
        return;
    }
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int t = 0;
        dp.resize(1001, vector<int>(1001, -1));
        for (int i = 0; i < n; i++) {
            solve(grid, i, 0 , 0, 0);
            t = max(t, maxmove);
            maxmove=0;
        }
        return t;
    }
};