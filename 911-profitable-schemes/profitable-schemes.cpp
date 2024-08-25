class Solution {
public:
    vector<vector<vector<int>>> dp;
    int N;
    int MOD = 1e9+7;
    int solve(int i, int p, int number_of_members, vector<int>& group,
              vector<int>& profit, int &minprofit) {
        if (number_of_members > N) {
            return 0;
        }
        if (dp[i][p][number_of_members] != -1) {
            return dp[i][p][number_of_members];
        }
        if (i == group.size()) {
            if (p >= minprofit) {
                return dp[i][p][number_of_members]=1;
            }
            return dp[i][p][number_of_members]=0;
        }
        long long nottaken =
            solve(i + 1, p, number_of_members, group, profit, minprofit) % MOD;
        long long  taken =
            solve(i + 1, min(p + profit[i], minprofit),
                  number_of_members + group[i], group, profit, minprofit) %
            MOD;
        return dp[i][p][number_of_members] =
                   (nottaken % MOD + taken % MOD) % MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group,
                          vector<int>& profit) {
        N = n;
        dp.clear();
        dp.resize(101, vector<vector<int>>(101, vector<int>(101, -1)));
        return solve(0, 0, 0, group, profit, minProfit);
    }
};