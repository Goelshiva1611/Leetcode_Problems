class Solution {
public:
    typedef pair<int, int> P;

    void dfs(int u, unordered_map<int, vector<P>>& adj, int mid,
             vector<bool>& visited) {
        visited[u] = true;

        // visit all ngbrs of u if possible
        for (auto& p : adj[u]) {
            int v = p.first;
            int w = p.second;

            if (w <= mid && !visited[v]) {
                dfs(v, adj, mid, visited);
            }
        }
    }
    void bfs(unordered_map<int, vector<P>>& adj, vector<bool>& visited,
             int max) {
        queue<int> qu;
        qu.push(0);
        visited[0] = true;
        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();
            for (auto& p : adj[u]) {
                int v = p.first;
                int wt = p.second;
                if (!visited[v] && wt <= max) {
                    visited[v] = true;
                    qu.push(v);
                }
            }
        }
    }
    bool canAllReachZero(int n, unordered_map<int, vector<P>>& adj, int mid) {
        // DFS
        vector<bool> visited(n, false);
        // dfs(0, adj, mid, visited);
        bfs(adj, visited, mid);
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                return false;
            }
        }

        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        unordered_map<int, vector<P>> adj;
        // u -> {(v1, w1), (v2,w2),... }

        int maxWt = 0;
        // Form the adj with reversed edge
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[v].push_back({u, w}); // with reversed edge
            maxWt = max(maxWt, w);
        }

        // apply binary search on answer (weight)
        int result = INT_MAX; // invalid answer

        int l = 0;
        int r = maxWt;

        // T.C : O(log(maxWt) * (V+E))
        // S.C : O(V+E)
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (canAllReachZero(n, adj, mid) ==
                true) { // O(V+E) due to BFS or DFS
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};
