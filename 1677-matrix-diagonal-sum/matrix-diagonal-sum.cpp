class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 1) {
            return mat[0][0];
        }
        if (n == 2) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    sum += mat[i][j];
                }
            }
            return sum;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += mat[i][i];
        }
        int j = n - 1;
        for (int i = 0; i < n; i++) {
            if (i != j)
                ans += mat[i][j];
            j--;
        }
        return ans;
    }
};