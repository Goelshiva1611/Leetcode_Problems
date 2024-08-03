class Solution {
public:
    int n;
    int solve(int i, vector<int>& days, vector<int>& costs, vector<int>& memo) {
        if (i >= n) {
            return 0;
        }
        
        if (memo[i] != -1) {
            return memo[i];
        }

        // Option 1: Buy 1-day pass
        int a = costs[0] + solve(i + 1, days, costs, memo);
        
        // Option 2: Buy 7-day pass
        int j = i;
        while (j < n && days[j] < days[i] + 7) {
            j++;
        }
        int b = costs[1] + solve(j, days, costs, memo);
        
        // Option 3: Buy 30-day pass
        j = i;
        while (j < n && days[j] < days[i] + 30) {
            j++;
        }
        int c = costs[2] + solve(j, days, costs, memo);

        return memo[i] = min({a, b, c});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        vector<int> memo(n, -1);
        return solve(0, days, costs, memo);
    }
};
