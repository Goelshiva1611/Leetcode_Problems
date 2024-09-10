class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        vector<int> v;
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            indegree[v]++;
        }
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                v.push_back(i);
            }
        }
        sort(v.begin(), v.end());
        return v;
    }
};