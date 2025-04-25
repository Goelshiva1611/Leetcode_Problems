class Solution {
public:
    vector<long long> dp;
    long long solve(vector<vector<int>>&questions, int i) {
        if (i >= questions.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        return dp[i] = max(questions[i][0] +
                               solve(questions, i + questions[i][1] + 1),
                           solve(questions, i + 1));
    }
    long long mostPoints(vector<vector<int>>& questions) {
        dp.resize(questions.size(), -1);
        return solve(questions, 0);
    }
};