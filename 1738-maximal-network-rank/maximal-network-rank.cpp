class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> adj1(n, vector<int>(n, 0));
        for (int i = 0; i < roads.size(); i++) {
            adj1[roads[i][0]][roads[i][1]] = 1;
            adj1[roads[i][1]][roads[i][0]] = 1;
        }
        int sum = 0;
        int ans = INT_MIN;
        for (int i = 0; i < adj.size(); i++) {
            for (int j = 0; j < adj.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (adj1[i][j] == 1) {
                    int u = adj[i].size();
                    int v = adj[j].size();
                    ans = max(ans, u + v - 1);
                } else {
                    int u = adj[i].size();
                    int v = adj[j].size();
                    ans = max(ans, u + v);
                }
            }
        }
        return ans;
    }
};