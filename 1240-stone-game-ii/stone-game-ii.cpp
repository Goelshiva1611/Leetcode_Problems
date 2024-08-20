class Solution {
public:
    int n;
    vector<vector<vector<int>>>dp;
    int solve(vector<int>& piles, int person, int i, int m) {
        if (i >= n) {
            return 0;
        }
        if(dp[person][i][m]!=-1)
        {
            return dp[person][i][m];
        }
        int stone = 0;
        int result = (person == 0) ? INT_MAX : 0;

        for (int x = 1; x <= min(2 * m, n - i); x++) {
            stone += piles[i + x - 1];
            if (person == 1) {
                result = max(result, stone + solve(piles, 0, i + x, max(m, x)));
            } else {
                result = min(result, solve(piles, 1, i + x, max(m, x)));
            }
        }
        return dp[person][i][m]=result;
    }
    int stoneGameII(vector<int>& piles) {
        dp.clear();
        dp.resize(2,vector<vector<int>>(101,vector<int>(101,-1)));
        n = piles.size();
        return solve(piles, 1, 0, 1);
    }
};