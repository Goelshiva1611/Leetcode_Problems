class Solution {
public:
    int n;
    int m;
    int color1;
    int c;
    void dfs(int i, int j, vector<vector<int>>& image,
             vector<vector<int>>& visited) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return;
        }
        if (visited[i][j] || image[i][j] != color1) {
            return;
        }
        visited[i][j] = 1;
        image[i][j] = c;
        dfs(i - 1, j, image, visited);
        dfs(i, j + 1, image, visited);
        dfs(i, j - 1, image, visited);
        dfs(i + 1, j, image, visited);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        n = image.size();
        m = image[0].size();
        c = color;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        color1 = image[sr][sc];
        if (color1 == color) {
            return image;
        }
        dfs(sr, sc, image, visited);
        return image;
    }
};