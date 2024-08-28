
class Solution {
public:
    int n;
    int m;
    void dfs(int i, int j, vector<vector<int>>& land,
             vector<vector<int>>& visited, vector<int>& v, int& t) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return;
        }
        if (visited[i][j] || land[i][j] == 0) {
            return;
        }
        visited[i][j] = 1;
        dfs(i + 1, j, land, visited, v, t);
        dfs(i, j + 1, land, visited, v, t);
        if (t == 1) {
            v.push_back(i);
            v.push_back(j);
            t = 0;
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size();
        m = land[0].size();
        int t = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> answer;
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<int> v;
                if (!visited[i][j] && land[i][j] == 1) {
                    v.push_back(i);
                    v.push_back(j);
                    t = 1;
                    dfs(i, j, land, visited, v, t);
                }
                if (v.size() != 0)
                    answer.push_back(v);
            }
        }
        return answer;
    }
};