class Solution {
public:
    int n = 0;
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i,
             int j, int& sum, int t) {
        if (i >= n || j >= n || i < 0 || j < 0 || visited[i][j] == true ||
            grid[i][j] == 0) {
            return;
        }
        sum += 1;
        visited[i][j] = true;
        grid[i][j] = t;
        dfs(grid, visited, i + 1, j, sum, t);
        dfs(grid, visited, i, j + 1, sum, t);
        dfs(grid, visited, i, j - 1, sum, t);
        dfs(grid, visited, i - 1, j, sum, t);
    }

    int largestIsland(vector<vector<int>>& grid) {
        int numberOfIsland = 0;
        n = grid.size();
        unordered_map<int, int> mp;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int t = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] != 0) {
                    t++;
                    int sum = 0;
                    dfs(grid, visited, i, j, sum, t);
                    cout << sum;
                    mp[t] = sum;
                }
            }
        }
        cout << endl;
        int m = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                set<int> st;
                if (grid[i][j] == 0) {
                    int s = 0;
                    if (i + 1 < n) {
                        st.insert(grid[i + 1][j]);
                    }
                    if (j + 1 < n) {
                        st.insert(grid[i][j + 1]);
                    }
                    if (i - 1 >= 0) {
                        st.insert(grid[i - 1][j]);
                    }
                    if (j - 1 >= 0) {
                        st.insert(grid[i][j - 1]);
                    }
                    for (auto it : st) {
                        s += mp[it];
                    }
                    cout << s;
                    s += 1;
                    m = max(m, s);
                }
            }
        }
        return (m == 0) ? n * n : m;
    }
};
/*
class Solution {
public:
    int n = 0;
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i,
             int j, int& sum) {
        if (i >= n || j >= n || i < 0 || j < 0 || visited[i][j] == true ||
            grid[i][j] == 0) {
            return;
        }
        sum += 1;
        visited[i][j] = true;
        dfs(grid, visited, i + 1, j, sum);
        dfs(grid, visited, i, j + 1, sum);
        dfs(grid, visited, i, j - 1, sum);
        dfs(grid, visited, i - 1, j, sum);
    }

    int largestIsland(vector<vector<int>>& grid) {
        int numberOfIsland=0;
        n = grid.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<bool>> visited(n, vector<bool>(n, false));
                if (grid[i][j] == 0) {
                    int sum = 0;
                    grid[i][j] = 1;
                    dfs(grid, visited, i, j, sum);
                    cout<<sum;
                    numberOfIsland = max(sum, numberOfIsland);
                    grid[i][j] = 0;
                }
            }
        }
        return (numberOfIsland == 0) ? n * n : numberOfIsland;
    }
};
*/