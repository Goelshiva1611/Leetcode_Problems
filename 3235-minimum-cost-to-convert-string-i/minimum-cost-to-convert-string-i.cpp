class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        int n = 26; // Considering 26 characters in the alphabet
        vector<vector<int>> edges;

        for (int i = 0; i < original.size(); i++) {
            edges.push_back({original[i] - 'a', changed[i] - 'a', cost[i]});
        }

        vector<vector<long long>> dist(n, vector<long long>(n, LLONG_MAX));

        for (auto& it : edges) {
            dist[it[0]][it[1]] = min((long long)it[2], dist[it[0]][it[1]]);
        }

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0; // Correctly setting the self-loop distance to 0
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long finalcost = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] == target[i]) {
                continue;
            }
            if (dist[source[i] - 'a'][target[i] - 'a'] == LLONG_MAX) {
                return -1;
            }
            finalcost += dist[source[i] - 'a'][target[i] - 'a'];
        }

        return finalcost;
    }
};