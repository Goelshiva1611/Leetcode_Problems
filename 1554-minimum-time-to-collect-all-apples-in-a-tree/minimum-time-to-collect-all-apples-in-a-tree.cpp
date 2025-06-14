class Solution {
public:
    int dfs(vector<vector<int>>& adj, int curr, int parent,
            vector<bool>& hasApple) {
        int time = 0;
        for (auto it : adj[curr]) {
            if (it == parent)
                continue;
            int time_by_child_below = dfs(adj, it, curr, hasApple);
            if (time_by_child_below > 0 || hasApple[it]) {
                time += time_by_child_below + 2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        int m = edges.size();
        for (int i = 0; i < m; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        return dfs(adj, 0, -1, hasApple);
    }
};