class Solution {
public:
    int r = 0;
    int c = 0;
    bool dfs(vector<vector<int>>& grid, int i, int j) {

        if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 1) {
            return false;
        }
        if (i == r - 1) {
            return true;
        }
        grid[i][j] = 1;
        return dfs(grid, i, j + 1) || dfs(grid, i + 1, j) ||
               dfs(grid, i - 1, j) || dfs(grid, i, j - 1);
    }
    bool canwego(vector<vector<int>>& cells, int mid) {
        vector<vector<int>> grid;
        grid.resize(r, vector<int>(c, 0));
        for (int i = 0; i <= mid; i++) {
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            grid[x][y] = 1;
        }

        for (int i = 0; i < c; i++) {
            if (grid[0][i] == 0) {
                if (dfs(grid, 0, i))
                    return true;
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        r = row;
        c = col;
        int low = 0;
        int high = cells.size() - 1;
        int answer = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canwego(cells, mid)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return answer + 1;
    }
};