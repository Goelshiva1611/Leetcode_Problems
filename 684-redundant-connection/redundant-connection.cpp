class Solution {
public:
    bool dfs(unordered_map<int, vector<int>> mp, vector<bool>& visited,
             int node, int parent) {
        if (node == parent) {
            return true;
        }
        cout << node;
        cout << parent;
        visited[node] = true;
        for (int i = 0; i < mp[node].size(); i++) {
            if (!visited[mp[node][i]] &&
                dfs(mp, visited, mp[node][i], parent)) {
                return true;
            }
        }
        return false;
    }
    bool bfs(unordered_map<int, vector<int>>& mp, vector<bool>& visited,
             int node, int end) {
        queue<int> qu;
        qu.push(node);
        while (!qu.empty()) {
            int n = qu.front();
            qu.pop();
            for (int i = 0; i < mp[n].size(); i++) {
                int a = mp[n][i];
                if (a == end) {
                    return true;
                }
                if (!visited[a]) {
                    visited[a] = true;
                    qu.push(a);
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < edges.size(); i++) {
            vector<bool> visited(edges.size(), false);
            if (mp.find(edges[i][1]) != mp.end() &&
                mp.find(edges[i][0]) != mp.end() &&
                bfs(mp, visited, edges[i][1], edges[i][0])) {
                return {edges[i][0], edges[i][1]};
            }
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        return {};
    }
};