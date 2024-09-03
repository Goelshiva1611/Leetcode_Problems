class Solution {
public:
    int n;
    int primsalgo(vector<vector<pair<int, int>>> adj) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        int sum = 0;
        vector<bool> ismst(n, false);
        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (ismst[node] == true) {
                continue;
            }
            ismst[node] = true;

            sum += wt;
            for (int i = 0; i < adj[node].size(); i++) {
                if (ismst[adj[node][i].first] == false) {
                    pq.push({adj[node][i].second, adj[node][i].first});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = points[j][0];
                int b = points[j][1];
                int c = points[i][0];
                int d = points[i][1];

                int dist = abs(a - c) + abs(b - d);

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        return primsalgo(adj);
    }
};