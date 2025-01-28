class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j,
             vector<vector<bool>>&visited, int& sum) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            visited[i][j] == true || grid[i][j] == 0) {
            return;
        }
        visited[i][j] = true;
        sum += grid[i][j];
        cout<<sum;
        dfs(grid, i + 1, j, visited, sum);
        dfs(grid, i, j + 1, visited, sum);
        dfs(grid, i, j - 1, visited, sum);
        dfs(grid, i - 1, j, visited, sum);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        int m = grid[0].size();
        vector<vector<bool>> visited;
        visited.resize(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] != 0) {
                    int sum = 0;
                    dfs(grid, i, j, visited, sum);
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
};