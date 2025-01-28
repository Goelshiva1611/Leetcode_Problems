class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j,
             vector<vector<bool>>& visited, int& sum) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            visited[i][j] == true || grid[i][j] == 0) {
            return;
        }
        visited[i][j] = true;
        sum += grid[i][j];
        for (int q = i + 1; q < grid.size(); q++)
            dfs(grid, q, j, visited, sum);
        for (int q = j + 1; q < grid[0].size(); q++)
            dfs(grid, i, q, visited, sum);
        for (int q = j - 1; q >= 0; q--)
            dfs(grid, i, q, visited, sum);
        for (int q = i - 1; q >= 0; q--)
            dfs(grid, q, j, visited, sum);
    }
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited;
        visited.resize(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] != 0) {
                    int sum = 0;
                    dfs(grid, i, j, visited, sum);
                    if (sum > 1)
                        ans += sum;
                }
            }
        }
        return ans;
    }
};