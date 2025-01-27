class Solution {
public:
    int ans = INT_MAX;
    void bfs(unordered_map<int, vector<int>>& mp, vector<int>& visited,
             vector<int>& dist, int node) {

        queue<pair<int, int>> qu;
        qu.push({node, -1});
        visited[node] = true;
        while (!qu.empty()) {
            int node = qu.front().first;
            int parent = qu.front().second;
            qu.pop();
            vector<int> nbh = mp[node];
            for (int i = 0; i < nbh.size(); i++) {
                int a = nbh[i];
                if (!visited[a]) {
                    dist[a] = dist[node] + 1;
                    visited[a] = true;
                    qu.push({a, node});
                } else if (a != parent) {
                    ans = min(ans, dist[a] + dist[node] + 1);
                }
            }
        }
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        for (int i = 0; i < n; i++) {
            vector<int> visited(n, false);
            vector<int> dist(n, 0);
            if (!visited[i]) {
                bfs(mp, visited, dist, i);
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};