class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // via toposort
        int n = graph.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                mp[graph[i][j]].push_back(i);
            }
        }
        vector<int> indegree(n, 0);
        for (auto it : mp) {
            vector<int> v = it.second;
            for (int i = 0; i < v.size(); i++) {
                indegree[v[i]]++;
            }
        }
        queue<int> qu;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                qu.push(i);
            }
        }
        vector<int> safenodes(n, -1);
        while (!qu.empty()) {
            int a = qu.front();
            qu.pop();
            safenodes[a] = a;
            for (int i = 0; i < mp[a].size(); i++) {
                indegree[mp[a][i]]--;
                if (indegree[mp[a][i]] == 0) {
                    qu.push(mp[a][i]);
                }
            }
        }
        vector<int> v;
        for (int i = 0; i < safenodes.size(); i++) {
            if (safenodes[i] != -1) {
                v.push_back(i);
            }
        }
        return v;
    }
};