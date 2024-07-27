class Solution {
public:
    int n;
    vector<vector<int>> v;
    int solve(vector<int>& prices, int day, bool buy) {
        if (day >= n) {
            return 0;
        }
        if (v[day][buy]!=-1) {
            return v[day][buy];
        }
        
        int profit = 0;
        if (buy) {
            int take = solve(prices, day + 1, false) - prices[day];
            int nottake = solve(prices, day + 1, true);
            profit = max({profit, take, nottake});
        } else {
            int sell = prices[day] + solve(prices, day + 2, true);
            int notsell = solve(prices, day + 1, false);
            profit = max({sell, notsell, profit});
        }

        return v[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        v.clear();
        v.resize(5001, vector<int>(2, -1));
        return solve(prices, 0, true);
    }
};