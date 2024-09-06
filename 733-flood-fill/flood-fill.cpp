class Solution {
public:
    int n;
    int m;
    int color_To_do;
    int color_initial;
    void dfs(int i, int j, vector<vector<int>>& image,
             vector<vector<int>>& visited) {

        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] ||
            image[i][j] != color_initial)
            return;
        visited[i][j] = 1;
        image[i][j] = color_To_do;
        dfs(i - 1, j, image, visited);
        dfs(i, j + 1, image, visited);
        dfs(i, j - 1, image, visited);
        dfs(i + 1, j, image, visited);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        n = image.size();
        m = image[0].size();
        color_To_do = color;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        color_initial = image[sr][sc];
        if (color_initial == color_To_do)
            return image;
        dfs(sr, sc, image, visited);
        return image;
    }
};