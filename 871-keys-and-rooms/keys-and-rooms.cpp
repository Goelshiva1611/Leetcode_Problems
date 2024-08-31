class Solution {
public:
    void dfs(vector<bool>& visited, int node, vector<vector<int>>& adj) {
        visited[node] = true;
        for (int i = 0; i < adj[node].size(); i++) {
            if (!visited[adj[node][i]] && adj[node][i] != node) {
                dfs(visited, adj[node][i], adj);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                adj[i].push_back(rooms[i][j]);
            }
        }

        vector<bool> visited(n, false);
        visited[0] = true;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                cout << i;
                cout << endl;
                dfs(visited, i, adj);
            }
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                return false;
            }
        }
        return true;
    }
};