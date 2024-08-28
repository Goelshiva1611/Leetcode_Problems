class Solution {
public:
    int n;
    int m;
    void dfs(int i, int j, vector<vector<int>>& grid,
             vector<vector<int>>& visited, int& sum) {
        if (i < 0 || i >= n || j >= m || j < 0) {
            return;
        }
        if (visited[i][j] == 1 || grid[i][j] == 0) {
            return;
        }
        visited[i][j] = 1;
        sum += grid[i][j];
        dfs(i + 1, j, grid, visited, sum);
        dfs(i, j + 1, grid, visited, sum);
        dfs(i - 1, j, grid, visited, sum);
        dfs(i, j - 1, grid, visited, sum);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<int> v;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == 0 && grid[i][j] >= 1) {
                    int sum = 0;
                    dfs(i, j, grid, visited, sum);
                    v.push_back(sum);
                }
            }
        }
        sort(v.rbegin(), v.rend());
        if (v.size() == 0) {
            return 0;
        }
        return v[0];
    }
};
