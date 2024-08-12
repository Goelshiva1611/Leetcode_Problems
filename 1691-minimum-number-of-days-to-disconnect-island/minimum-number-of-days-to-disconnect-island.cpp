class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j,
             vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 ||
            visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        dfs(grid, i + 1, j, visited);
        dfs(grid, i - 1, j, visited);
        dfs(grid, i, j + 1, visited);
        dfs(grid, i, j - 1, visited);
    }
    int numberofislands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int island = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == false && grid[i][j] == 1) {
                    dfs(grid, i, j, visited);
                    island++;
                }
            }
        }
        return island;
    }
    int minDays(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int island = numberofislands(grid);
        if (island > 1 || island == 0) {
            return 0;
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 1) {
                        grid[i][j] = 0;
                        int t = numberofislands(grid);
                        if (t > 1 || t == 0) {
                            return 1;
                        }
                        grid[i][j] = 1;
                    }
                }
            }
        }
        return 2;
    }
};