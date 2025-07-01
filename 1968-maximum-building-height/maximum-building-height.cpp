class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // Add building 1 with height 0
        restrictions.push_back({1, 0});
        // Add building n with maximum possible height
        if (restrictions.empty() || restrictions.back()[0] != n)
            restrictions.push_back({n, n - 1});

        // Sort by building index
        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // Forward pass to limit heights
        for (int i = 1; i < m; ++i) {
            int d = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + d);
        }

        // Backward pass to limit heights
        for (int i = m - 2; i >= 0; --i) {
            int d = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + d);
        }

        int ans = 0;
        for (int i = 1; i < m; ++i) {
            int l = restrictions[i - 1][0], r = restrictions[i][0];
            int hl = restrictions[i - 1][1], hr = restrictions[i][1];
            int dist = r - l;

            // Max possible peak height between hl and hr
            int peak = (hl + hr + dist) / 2;
            ans = max(ans, peak);
        }

        return ans;
    }
};
