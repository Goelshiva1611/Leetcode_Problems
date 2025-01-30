class Solution {
public:
    bool checkDfsBipartite(unordered_map<int, vector<int>>& mp, int curr,
                           vector<int>& colors) {
        colors[curr] = 1;
        for (int i = 0; i < mp[curr].size(); i++) {
            if (colors[mp[curr][i]] == colors[curr])
                return false;
            else if (colors[mp[curr][i]] == -1) {
                colors[mp[curr][i]] = 1 - colors[curr];
                if (checkDfsBipartite(mp, mp[curr][i], colors) == false) {
                    return false;
                }
            }
        }
        return true;
    }
    bool checkBfsBipartite(unordered_map<int, vector<int>>& mp, int curr,
                           vector<int>& colors) {

        queue<int> qu;
        qu.push(curr);
        colors[curr] = 1;
        while (!qu.empty()) {
            int node = qu.front();
            qu.pop();
            for (int i = 0; i < mp[node].size(); i++) {
                if (colors[mp[node][i]] == colors[node]) {
                    return false;
                } else if (colors[mp[node][i]] == -1) {
                    colors[mp[node][i]] = 1 - colors[node];
                    qu.push(mp[node][i]);
                }
            }
        }
        return true;
    }
    int levelBfs(unordered_map<int, vector<int>>& mp, int node) {
        queue<int> qu;
        int level = 0;
        qu.push(node);
        vector<bool> visited(mp.size(), false);
        visited[node] = true;
        while (!qu.empty()) {
            int size = qu.size();
            while (size--) {
                int first = qu.front();
                qu.pop();
                for (int i = 0; i < mp[first].size(); i++) {
                    if (!visited[mp[first][i]]) {
                        visited[mp[first][i]] = true;
                        qu.push(mp[first][i]);
                    }
                }
            }
            level++;
        }
        return level;
    }
    int findMaxlevelBfs(unordered_map<int, vector<int>>& mp, int node,
                        vector<bool>& visited, vector<int>& levels) {
        queue<int> qu;
        qu.push(node);
        int maxlevel = levels[node];
        visited[node] = true;
        while (!qu.empty()) {
            int node = qu.front();
            qu.pop();
            for (int i = 0; i < mp[node].size(); i++) {
                int a = mp[node][i];
                if (!visited[a]) {
                    visited[a] = true;
                    qu.push(a);
                    maxlevel = max(maxlevel, levels[a]);
                }
            }
        }
        return maxlevel;
    }
    int findMaxlevelDfs(unordered_map<int, vector<int>>& mp, int node,
                        vector<bool>& visited, vector<int>& levels) {

        int maxlevel = levels[node];
        visited[node] = true;
        for (int i = 0; i < mp[node].size(); i++) {
            int a = mp[node][i];
            if (!visited[a]) {
                maxlevel =
                    max(maxlevel, findMaxlevelDfs(mp, a, visited, levels));
            }
        }
        return maxlevel;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<int> colors(n, -1);
        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                if (checkBfsBipartite(mp, i, colors) == false) {
                    return -1;
                }
            }
        }
        int maxgroups = 0;
        vector<int> levels(n);
        for (int i = 0; i < n; i++) {
            levels[i] = levelBfs(mp, i);
            cout << levels[i];
        }
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                maxgroups += findMaxlevelDfs(mp, i, visited, levels);
            }
        }
        return maxgroups;
    }
};