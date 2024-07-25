class Solution {
public:
    int n;
    vector<int> v;
    int solve(vector<int>& cost, int i) {
        if (i >= n) {
            return 0;
        }
        if (v[i] != -1) {
            return v[i];
        }
        int onestep = solve(cost, i + 1);
        int twostep = solve(cost, i + 2);
        return v[i] = cost[i] + min(onestep, twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        v.clear();
        v.resize(1001, -1);
        n = cost.size();
        int i = 0;
        return min(solve(cost, i), solve(cost, i + 1));
    }
};