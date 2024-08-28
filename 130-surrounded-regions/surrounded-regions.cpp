class Solution {
public:
    int n;
    int m;
    void dfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<int>>& visited) {
        if (i < 0 || i >= n || j >= m || j < 0) {
            return;
        }
        if (visited[i][j] == 1 || grid[i][j] == 'X') {
            return;
        }
        visited[i][j] = 1;
        dfs(i + 1, j, grid, visited);
        dfs(i, j + 1, grid, visited);
        dfs(i - 1, j, grid, visited);
        dfs(i, j - 1, grid, visited);
    }
    void dfs1(int i, int j, vector<vector<char>>& grid,
              vector<vector<int>>& visited) {
        if (i < 0 || i >= n || j >= m || j < 0) {
            return;
        }
        if (visited[i][j] == 1 || grid[i][j] == 'X') {
            return;
        }
        visited[i][j] = 1;
        grid[i][j] = 'X';
        cout << "hello";
        dfs1(i + 1, j, grid, visited);
        dfs1(i, j + 1, grid, visited);
        dfs1(i - 1, j, grid, visited);
        dfs1(i, j - 1, grid, visited);
    }
    void solve(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {

            if (visited[i][0] == 0 && grid[i][0] == 'O') {
                dfs(i, 0, grid, visited);
            }
            if (visited[i][m - 1] == 0 && grid[i][m - 1] == 'O') {

                dfs(i, m - 1, grid, visited);
            }
            visited[i][m - 1] = 1;
            visited[i][0] = 1;
        }
        for (int j = 0; j < m; j++) {
            if (visited[0][j] == 0 && grid[0][j] == 'O') {
                dfs(0, j, grid, visited);
            }
            // cout<<visited[n-1][j];
            if (visited[n - 1][j] == 0 && grid[n - 1][j] == 'O') {
                dfs(n - 1, j, grid, visited);
            }
            visited[0][j] = 1;
            visited[n - 1][j] = 1;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == 0 && grid[i][j] == 'O') {
                    cout<<"hcdsb";
                    dfs1(i, j, grid, visited);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << visited[i][j];
                cout << " ";
            }
            cout << "\n";
        }
    }
};