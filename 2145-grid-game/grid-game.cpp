class Solution {
public:
    typedef long long l;
    long long gridGame(vector<vector<int>>& grid) {
        l n = grid.size(), m = grid[0].size(), fr = 0, sum = 0;
        for (int i = 0; i < m; i++)
            fr += grid[0][i];
        fr -= grid[0][0];
        l robot2 = fr;
        for (int i = 1; i < m; i++) {
            fr -= grid[0][i];
            sum += grid[1][i - 1];
            robot2 = min(robot2, max(sum, fr));
        }
        return robot2;
    }
};