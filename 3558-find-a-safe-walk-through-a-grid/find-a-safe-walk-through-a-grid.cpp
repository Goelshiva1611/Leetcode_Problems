class Solution {
public:
    vector<vector<vector<int>>> dp;
    int n = 0;
    int m = 0;
    int healt = 0;

    bool solve(int currentx, int currenty, vector<vector<int>>& grid, int h,
               vector<vector<bool>>& visited) {
        if (h >= healt)
            return false;
        if (currentx == n - 1 && currenty == m - 1)
            return true;
        if (dp[currentx][currenty][h] != -1)
            return dp[currentx][currenty][h];

        vector<int> dirx = {1, -1, 0, 0};
        vector<int> diry = {0, 0, 1, -1};

        visited[currentx][currenty] = true;

        for (int i = 0; i < 4; i++) {
            int newx = currentx + dirx[i];
            int newy = currenty + diry[i];

            if (newx >= 0 && newx < n && newy >= 0 && newy < m &&
                !visited[newx][newy]) {
                if (solve(newx, newy, grid, h + grid[newx][newy], visited)) {
                    visited[currentx][currenty] = false;
                    return true;
                }
            }
        }

        visited[currentx][currenty] = false;
        return dp[currentx][currenty][h] = false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        healt = health;
        n = grid.size();
        m = grid[0].size();
        dp.resize(n, vector<vector<int>>(m, vector<int>(100, -1)));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        return solve(0, 0, grid, grid[0][0], visited);
    }
};
