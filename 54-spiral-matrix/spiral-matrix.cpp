class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int rstart = 0, cstart = 0;
        int left = 0, right = m - 1, top = 0, bottom = n - 1;
    int d=0;
        while (ans.size() < n * m) {
            if (d == 0) {
                for (int j = left; j <= right; j++) {
                    ans.push_back(matrix[top][j]);
                }
                top++;
            } else if (d == 1) {
                for (int i = top; i <= bottom; i++) {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            } else if (d == 2) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            } else if (d == 3) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }

            d = (d + 1) % 4;
        }

        return ans;
    }
};
