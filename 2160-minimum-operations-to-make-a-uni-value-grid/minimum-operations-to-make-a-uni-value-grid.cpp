class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> p;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p.push_back(grid[i][j]);
            }
        }
        int count = 0;
        sort(p.begin(), p.end());
        for (int i = 0; i < p.size() - 1; i++) {
            if ((p[i + 1] - p[i]) % x != 0) {
                return -1;
            }
        }
        int mid = p[p.size() / 2];
        for (int i = 0; i < p.size(); i++) {
            count += abs(mid - p[i]) / x;
        }
        return count;
    }
};