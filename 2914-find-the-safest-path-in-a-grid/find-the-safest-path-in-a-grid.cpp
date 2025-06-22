// step1- multisourcebfs
// step2- binary search
// step3- simplebfs
class Solution {
public:
    typedef long long int ll;
    vector<int> x = {0, 1, -1, 0};
    vector<int> y = {1, 0, 0, -1};
    bool check_possible(vector<vector<int>>& final, int sf) {
        queue<pair<int, int>> qu;
        int n = final.size();
        int m = final[0].size();
        if (final[0][0] == 0 ||
            final[final.size() - 1][final[0].size() - 1] == 0 ||
            final[0][0] < sf || final[n - 1][m - 1] < sf) {
            return false;
        }
        vector<vector<int>> visited(n, vector<int>(m, false));
        qu.push({0, 0});
        while (!qu.empty()) {
            int size = qu.size();
            while (size--) {
                int a = qu.front().first;
                int b = qu.front().second;
                qu.pop();
                if (a == n - 1 && b == m - 1) {
                    return true;
                }
                for (int i = 0; i < 4; i++) {
                    int newx = a + x[i];
                    int newy = b + y[i];
                    if (newx >= 0 && newx < n && newy >= 0 && newy < m &&
                        visited[newx][newy] == false) {
                        if (final[newx][newy] >= sf) {
                            qu.push({newx, newy});
                            visited[newx][newy] = true;
                        }
                    }
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> final(n, vector<int>(m, 0));
        queue<pair<int, int>> qu;
        vector<vector<int>> visited(n, vector<int>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    qu.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        while (!qu.empty()) {
            int size = qu.size();
            while (size--) {
                int a = qu.front().first;
                int b = qu.front().second;
                qu.pop();
                for (int i = 0; i < 4; i++) {
                    int newx = a + x[i];
                    int newy = b + y[i];
                    if (newx >= 0 && newx < n && newy >= 0 && newy < m &&
                        visited[newx][newy] == false) {
                        ll distance =
                            final[a][b] + abs(a - newx) + abs(b - newy);
                        qu.push({newx, newy});
                        visited[newx][newy] = true;
                        final[newx][newy] = distance;
                    }
                }
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << final[i][j];
        //         cout << " ";
        //     }
        //     cout << endl;
        // }

        int low = 0;
        int high = INT_MAX;
        int answer = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check_possible(final, mid)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return answer;
    }
};