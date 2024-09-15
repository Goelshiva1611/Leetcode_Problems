class Solution {
public:
    vector<vector<long long int>> dp;
    long long int solve(int t, vector<int>& a, vector<int>& b, int index) {

        if (t == 4) {
            return 0;
        }   
        if(index>=b.size())
        {
            return INT_MIN;
        }
        if (dp[t][index] != -1) {
            return dp[t][index];
        }
        long long int take=(long long )a[t] * (long long )b[index] + solve(t + 1, a, b, index + 1);
        long long int nottake=solve(t, a, b, index + 1);
        return dp[t][index] = max(take, nottake);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        dp.clear();
        dp.resize(4, vector<long long int>(100004, -1));
        return solve(0, a, b, 0);
    }
};