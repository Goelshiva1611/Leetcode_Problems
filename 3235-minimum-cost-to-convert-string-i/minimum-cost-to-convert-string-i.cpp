
class Solution {

public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        int n = 26;
        vector<vector<int>> edges;

        for (int i = 0; i < original.size(); i++) {
            edges.push_back({original[i] - 'a', changed[i] - 'a', cost[i]});
        }

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for (auto& it : edges) {
            dist[it[0]][it[1]] = min(it[2], dist[it[0]][it[1]]);
        }

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long  finalcost = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] == target[i]) {
                continue;
            }
            if (dist[source[i] - 'a'][target[i] - 'a'] == INT_MAX) {
                return -1;
            }
            finalcost += dist[source[i] - 'a'][target[i] - 'a'];
        }

        return finalcost;
    }
};
