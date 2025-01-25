class Solution {
public:
    int m = 0;
    void cycleindfs(vector<int>& edges, vector<bool>& visited,
                    vector<bool>& recursion, int i, vector<int>& count) {
        if (edges[i] != -1) {

            visited[i] = true;
            recursion[i] = true;

            if (edges[i] != -1 && visited[edges[i]] == false) {
                count[edges[i]] = count[i] + 1;
                cycleindfs(edges, visited, recursion, edges[i], count);
            } else if (edges[i] != -1 && recursion[edges[i]] == true) {
                m = max(m, count[i] - count[edges[i]] + 1);
            }
            recursion[i] = false;
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<bool> recursion(n, false);
        vector<int> count(n, 1);
        for (int i = 0; i < n; i++) {
            if (!visited[i] && edges[i] != -1) {
                cycleindfs(edges, visited, recursion, i, count);
            }
        }
        return m == 0 ? -1 : m;
    }
};