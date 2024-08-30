#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    long long mod = (int)1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1; // If there's only one node, there's exactly one path
                      // (itself).

        // Adjacency list to store the graph
        vector<vector<pair<int, int>>> adj(n);

        // Populate the graph
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Priority queue for Dijkstra's algorithm
        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            pq;

        // Distance vector initialized to infinity
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0; // Start node distance

        // Ways vector to count the number of shortest paths
        vector<long long> ways(n, 0);
        ways[0] = 1; // There's exactly one way to reach the start node

        // Start with the source node
        pq.push({0, 0}); // {distance, node}

        while (!pq.empty()) {
            long long dis = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            // Iterate over adjacent nodes
            for (const auto& neighbor : adj[node]) {
                long long adjnode = neighbor.first;
                long long w_adj_node = neighbor.second;

                // Relaxation step
                if (dist[adjnode] > dis + w_adj_node) {
                    dist[adjnode] = dis + w_adj_node;
                    pq.push({dist[adjnode], adjnode});
                    ways[adjnode] = ways[node];
                } else if (dist[adjnode] == dis + w_adj_node) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }

        // Return the number of shortest paths to the target node
        return ways[n - 1]%mod;
    }
};
