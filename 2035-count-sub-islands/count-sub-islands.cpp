class Solution {
public:
    int n;
    int m;
    void dfs(int i, int j, vector<vector<int>>& grid1,
             vector<vector<int>>& grid2, vector<vector<int>>& visited,
             int& t) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return;
        }
        if (grid2[i][j] == 0 || visited[i][j] == 1) {
            return;
        }
        visited[i][j] = 1;
        if (grid1[i][j] == 0) {
            t = 0;
        }
        dfs(i + 1, j, grid1, grid2, visited, t);
        dfs(i, j - 1, grid1, grid2, visited, t);
        dfs(i, j + 1, grid1, grid2, visited, t);
        dfs(i - 1, j, grid1, grid2, visited, t);
    }
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();
        int count = 0;
        int t = 1;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && !visited[i][j]) {
                    t=1;
                    dfs(i, j, grid1, grid2, visited, t);
                    if (t == 1) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};