class Dsu {
public:
    vector<int> parent;
    vector<int> rank;
    Dsu(int n) {
        parent.resize(n, 0);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int i) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    void Union(int a, int b) {
        int a_parent = find(a);
        int b_parent = find(b);
        if (a_parent == b_parent) {
            return;
        }
        if (rank[a_parent] < rank[b_parent]) {
            parent[a_parent] = b_parent;
        } else if (rank[a_parent] > rank[b_parent]) {
            parent[b_parent] = a_parent;
        } else {
            parent[a_parent] = b_parent;
            rank[b_parent] += 1;
        }
        return;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        Dsu dsu(n);
        for (auto it : edges) {
            int a = it[0];
            int b = it[1];
            if (dsu.find(a - 1) == dsu.find(b - 1)) {
                return it;
            }
            dsu.Union(a - 1, b - 1);
        }
        return {};
    }
};