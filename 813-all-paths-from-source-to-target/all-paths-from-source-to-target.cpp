class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<vector<int>>& t,
             vector<int>& v) {
        v.push_back(node);
        if (node == graph.size() - 1) {
            t.push_back(v);
        }
        for (int i = 0; i < graph[node].size(); i++) {
            dfs(graph[node][i], graph, t, v);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> t;
        vector<int> v;
        dfs(0, graph, t, v);
        return t;
    }
};