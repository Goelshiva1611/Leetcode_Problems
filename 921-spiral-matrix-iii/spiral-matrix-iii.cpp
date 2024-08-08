class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {

        vector<pair<int, int>> direction(4);
        vector<vector<int>> ans;
        ans.push_back({rStart, cStart});
        // row,col
        direction[0] = {0, 1};
        direction[1] = {1, 0};
        direction[2] = {0, -1};
        direction[3] = {-1, 0};
        int steps = 0;
        int dir = 0;
        while (ans.size() < rows * cols) {
            if (dir == 0 || dir == 2) {
                steps++;
            }

            for (int i = 0; i < steps; i++) {
                rStart += direction[dir].first;
                cStart += direction[dir].second;
                if (rStart >= 0 && rStart < rows && cStart < cols &&
                    cStart >= 0) {
                    ans.push_back({rStart, cStart});
                }
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};
