class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int opt = 0;
        for (int i = 0; i < n; i++) {
            int p = 0;
            int t = grid[0][i];
            for (int j = 1; j < m; j++) {
                int q = grid[j][i] - t;
                if (q <= 0) {
                    opt += abs(q) + 1;
                    cout << opt;
                    t = t + 1;
                } else {
                    t = grid[j][i];
                }
            }
        }
        return opt;
    }
};