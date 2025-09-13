class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int up = INT_MAX;
        int down = INT_MIN;
        int left = INT_MAX;
        int right = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    up = min(up, i);
                    down = max(down, i);
                    left = min(left, j);
                    right = max(right, j);
                }
            }
        }
        int b=(down-up+1);
        int l=(right-left+1);
        return l*b;
    }
};