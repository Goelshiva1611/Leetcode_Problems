class Solution {
public:
    int t = 0;
    int x = 0;
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& stayScore, vector<vector<int>>& travelScore,
              int city, int day) {
        if (day == t) {
            return 0;
        }
        if (dp[city][day] != -1) {
            return dp[city][day];
        }
        int stay =
            stayScore[day][city] + solve(stayScore, travelScore, city, day + 1);
        int m = 0;
        for (int j = 0; j < x; j++) {
            if (city != j)
                m = max(m, travelScore[city][j] +
                               solve(stayScore, travelScore, j, day + 1));
        }
        return dp[city][day] = max(stay, m);
    }
    int maxScore(int n, int k, vector<vector<int>>& stayScore,
                 vector<vector<int>>& travelScore) {
        t = k;
        x = n;
        dp.resize(201, vector<int>(201, -1));
        int m = 0;
        for (int i = 0; i < n; i++) {
            m = max(m, solve(stayScore, travelScore, i, 0));
        }
        return m;
    }
};