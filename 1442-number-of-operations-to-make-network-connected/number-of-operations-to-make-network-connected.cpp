class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>&adj, int& t,
             int& x) {
        visited[node] = true;
        t++;
        x += adj[node].size();
        for (int i = 0; i < adj[node].size(); i++) {

            if (!visited[adj[node][i]]) {
                dfs(adj[node][i], visited, adj, t, x);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count = 0;
        int extra_edges=0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int t = 0;//vertices 
                int x = 0;//edges 
                dfs(i, visited, adj, t, x);
                cout<<t;
                x=x/2;
                if(x>=t-1)
                {
                    extra_edges+=(x-t+1);
                }
                count++;
            }
        }
        cout<<count;
        if(extra_edges>=count-1)
        {
            return count-1;
        }
        return -1;
    }
};
