class Solution {
public:
    void dfs(vector<bool>& visited, vector<vector<int>>& adj, int node) {
        visited[node] = true;
        for (int i = 0; i < adj[node].size(); i++) {
            if (!visited[adj[node][i]]) {
                dfs(visited, adj, adj[node][i]);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj(isConnected.size());
        vector<bool> visited(isConnected.size(), false);
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected.size(); j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    cout << i;
                    cout << j;
                    adj[i].push_back(j);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                count++;
                dfs(visited, adj, i);
            }
        }
        return count;
    }
};