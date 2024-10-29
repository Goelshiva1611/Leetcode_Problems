class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int solve(vector<vector<int>>& grid, int i, int j) {
        // Out of bounds check
        if (i >= n || i < 0 || j >= m || j < 0) return 0;

        // If already calculated, use stored result
        if (dp[i][j] != -1) return dp[i][j];

        int max_moves = 0;
        int current_value = grid[i][j];

        // Explore the three possible moves to the right
        if (i > 0 && j + 1 < m && grid[i - 1][j + 1] > current_value) 
            max_moves = max(max_moves, 1 + solve(grid, i - 1, j + 1));
        
        if (j + 1 < m && grid[i][j + 1] > current_value)
            max_moves = max(max_moves, 1 + solve(grid, i, j + 1));

        if (i + 1 < n && j + 1 < m && grid[i + 1][j + 1] > current_value)
            max_moves = max(max_moves, 1 + solve(grid, i + 1, j + 1));

        // Store the result in dp array
        dp[i][j] = max_moves;
        return max_moves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n, vector<int>(m, -1)); // Resize dp array based on grid size

        int max_moves = 0;

        // Start DFS from the first column of each row
        for (int i = 0; i < n; i++) {
            max_moves = max(max_moves, solve(grid, i, 0));
        }

        return max_moves;
    }
};
