class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>image1(n,vector<int>(n,-1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (image[i][m - j - 1] == 1) {
                    cout<<image[i][j];
                    image1[i][j] = 0;
                } else if(image[i][m - j - 1] == 0){
                    image1[i][j] = 1;
                }
            }
        }
        return image1;
    }
};