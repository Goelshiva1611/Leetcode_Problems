class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<bool>> visited(isWater.size(),
                                     vector<bool>(isWater[0].size(), false));
        vector<vector<int>> heights(isWater.size(),
                                    vector<int>(isWater[0].size(), 0));
        queue<pair<int, int>> qu;
        for (int i = 0; i < isWater.size(); i++) {
            for (int j = 0; j < isWater[0].size(); j++) {
                if (isWater[i][j] == 1) {
                    qu.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        while (!qu.empty()) {
            int size = qu.size();
            while (size--) {
                auto it = qu.front();
                qu.pop();
                int i = it.first;
                int j = it.second;
                if (i + 1 < n && heights[i + 1][j] == 0 && !visited[i + 1][j]) {
                    qu.push({i + 1, j});
                    visited[i + 1][j] = true;
                    heights[i + 1][j] = heights[i][j] + 1;
                }
                if (i - 1 >= 0 && heights[i - 1][j] == 0 &&
                    !visited[i - 1][j]) {
                    qu.push({i - 1, j});
                    visited[i - 1][j] = true;
                    heights[i - 1][j] = heights[i][j] + 1;
                }
                if (j + 1 < m && heights[i][j + 1] == 0 && !visited[i][j + 1]) {
                    qu.push({i, j + 1});
                    visited[i][j + 1] = true;
                    heights[i][j + 1] = heights[i][j] + 1;
                }
                if (j - 1 >= 0 && heights[i][j - 1] == 0 &&
                    !visited[i][j - 1]) {
                    qu.push({i, j - 1});
                    visited[i][j - 1] = true;
                    heights[i][j - 1] = heights[i][j] + 1;
                }
            }
        }
        return heights;
    }
};