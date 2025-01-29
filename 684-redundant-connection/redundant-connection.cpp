class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>&mp, vector<bool>& visited,
                     int node, int parent) {
        visited[node] = true;
        for (int i = 0; i < mp[node].size(); i++) {
            if (!visited[mp[node][i]]) {
                dfs(mp, visited, mp[node][i], node);
            } else if (visited[mp[node][i]] && mp[node][i] != parent) {
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < edges.size(); i++) {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
            vector<bool> visited(edges.size(), false);
            if(dfs(mp, visited, edges[i][0], -1))
            {
                return {edges[i][0],edges[i][1]};
            }
        }
        return {};
    }
};