class Solution {
public:
    vector<int> parent, sz;

    int find_set(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find_set(parent[x]);
    }

    bool make_union(int x, int y) {
        int a = find_set(x);
        int b = find_set(y);
        if (a == b)
            return true;
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return false;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        vector<int> indeg(n + 1, -1);
        int b1 = -1, b2 = -1;
        for (int i = 0; i < edges.size(); i++) {
            if (indeg[edges[i][1]] == -1) {
                indeg[edges[i][1]] = i;
            } else {
                b1 = i;
                b2 = indeg[edges[i][1]];
                break;
            }
        }
        cout << b1;

        for (int i = 0; i < edges.size(); i++) {

            if(i == b1) continue;

            int u = edges[i][0];
            int v = edges[i][1];
            if (make_union(u, v)) {

                if (b1 == -1)
                    return {u, v};

                else
                    return {edges[b2][0], edges[b2][1]};
            }
        }
        return {edges[b1][0], edges[b1][1]};
    }
};