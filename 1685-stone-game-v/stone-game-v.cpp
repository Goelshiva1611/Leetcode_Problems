class Solution {
public:
    vector<vector<int>> v;
    int solve(int l, int r, vector<int>& stone) {
        if (l == r) {
            return 0;
        }
        if (v[l][r] != -1) {
            return v[l][r];
        }
        int sum = 0;
        int sum1 = 0;
        int result = 0;
        int ans = INT_MIN;
        for (int i = l; i <= r; i++) {
            sum += stone[i];
        }
        for (int i = l; i < r; i++) {
            sum1 += stone[i];
            sum -= stone[i];
            if (sum1 < sum) {
                result = sum1 + solve(l, i, stone);
            } else if (sum1 == sum) {
                int result1 = sum1 + solve(l, i, stone);
                int result2 = sum1 + solve(i + 1, r, stone);
                result = max(result1, result2);
            } else {
                result = sum + solve(i + 1, r, stone);
            }
            ans = max(ans, result);
        }
        return v[l][r] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        v.clear();
        v.resize(505, vector<int>(505, -1));
        return solve(0, stoneValue.size() - 1, stoneValue);
    }
};