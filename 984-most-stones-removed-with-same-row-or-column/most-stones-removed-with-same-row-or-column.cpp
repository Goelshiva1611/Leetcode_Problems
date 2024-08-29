class Solution {
public:
    int n;
    void dfs(int index, vector<bool> &visited, vector<vector<int>> &stones) {
        visited[index] = true;
        for (int i = 0; i < n; i++) {
            int row = stones[i][0];
            int col = stones[i][1];
            if (visited[i]==false &&
                (stones[index][0] == row || stones[index][1] == col)) {
                dfs(i, visited, stones);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int group = 0;
        n = stones.size();
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (visited[i]==false) {
                dfs(i, visited, stones);
                group++;
                cout<<"hello";
            }
        }
        return n - group;
    }
};