class Solution {
public:
    void dfs(int node, vector<bool>& visited, const vector<vector<int>>& adj, long long& size) {
        visited[node] = true;
        size += 1;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adj, size);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(n, false);
        long long result = 0;
        long long remaining = n;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                long long size = 0;
                dfs(i, visited, adj, size);
                result += size * (remaining - size);
                remaining -= size;
            }
        }
        
        return result;
    }
};
