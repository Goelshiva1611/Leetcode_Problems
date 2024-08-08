class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int rstart = 0, cstart = 0;
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int d = 0;
        int a=1;
        while (a <= n * n) {
            if (d == 0) {
                for (int j = left; j <= right; j++) {
                    matrix[top][j]=a;
                    a++;
                }
                top++;
            } else if (d == 1) {
                for (int i = top; i <= bottom; i++) {
                    matrix[i][right]=a;
                    a++;
                }
                right--;
            } else if (d == 2) {
                for (int j = right; j >= left; j--) {
                    matrix[bottom][j]=a;
                    a++;
                }
                bottom--;
            } else if (d == 3) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left]=a;
                    a++;
                }
                left++;
            }

            d = (d + 1) % 4;
        }
        return  matrix;
    }
};