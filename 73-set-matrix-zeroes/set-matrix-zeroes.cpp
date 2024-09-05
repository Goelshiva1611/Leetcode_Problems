class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> matrix1 = matrix;
        for (int i = 0; i < n; i++) {
            bool flag = false;
            for (int j = 0; j < m; j++) {
                cout<<matrix1[i][j];
                if (matrix1[i][j] == 0) {
                    for (int q = 0; q < m; q++) {
                        matrix[i][q] = 0;
                    }
                    for (int q = 0; q < n; q++) {
                        matrix[q][j] = 0;
                    }
                }
            }
        }
    }
};