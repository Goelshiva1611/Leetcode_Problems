class Solution {
public:
    int n;
    int m;
    void dfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<int>>& visited) {
        if (i < 0 || i >= n || j >= m || j < 0) {
            return;
        }
        if (visited[i][j] == 1 || grid[i][j] == '.') {
            return;
        }
        visited[i][j] = 1;
        dfs(i + 1, j, grid, visited);
        dfs(i, j + 1, grid, visited);
        dfs(i - 1, j, grid, visited);
        dfs(i, j - 1, grid, visited);
    }
    int countBattleships(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<int> v;
        int count = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == 0 && grid[i][j] == 'X') {
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return count;
    }
};