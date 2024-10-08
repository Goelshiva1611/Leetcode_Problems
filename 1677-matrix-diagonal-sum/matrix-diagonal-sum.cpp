class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 1) {
            return mat[0][0];
        }
        int j = n - 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += mat[i][i];
            if (i != j)
                ans += mat[i][j];
            j--;
        }
        return ans;
    }
};