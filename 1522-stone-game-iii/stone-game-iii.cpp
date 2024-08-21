class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int i, vector<int>& stone) {
        if (i >= n) {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int result = stone[i] - solve(i + 1, stone);
        if (i + 1 < n)
            result = max(result, stone[i] + stone[i+1] - solve(i + 2, stone));
        if (i + 2 < n)
            result = max(result,
                         stone[i] + stone[i+1] + stone[i+2] - solve(i + 3, stone));

        return dp[i]=result;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        dp.clear();
        dp.resize(500005,-1);
        n=stoneValue.size();
        if (solve(0, stoneValue) < 0) {
            return "Bob";
        } else if (solve(0, stoneValue) > 0) {
            return "Alice";
        }
        return "Tie";
    }
};