class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int t = 0;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (t == 0) {
                for (int j = 0; j < m; j += 2) {
                    cout << j;
                    v.push_back(grid[i][j]);
                }
            }
            else
            {
                int p=(m%2==0)?m-1:m-2;
                for (int j = p; j >=0; j -= 2) {
                    cout << j;
                    v.push_back(grid[i][j]);
                }
            }
            t = !t;
        }

        return v;
    }
};