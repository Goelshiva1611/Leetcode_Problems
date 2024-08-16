class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        vector<pair<int, int>> minimum;
        vector<pair<int, int>> maximum;
        for (int i = 0; i < n; i++) {
            minimum.push_back({arrays[i][0], i});
            maximum.push_back({arrays[i][arrays[i].size() - 1], i});
        }
        sort(minimum.begin(), minimum.end());
        sort(maximum.rbegin(), maximum.rend());
        int maxim = 0;
        if (minimum[0].second == maximum[0].second) {
            maxim = abs(minimum[0].first - maximum[1].first);
            maxim = max(maxim, abs(minimum[1].first - maximum[0].first));
            return maxim;
        }
        return abs(minimum[0].first - maximum[0].first);
    }
};