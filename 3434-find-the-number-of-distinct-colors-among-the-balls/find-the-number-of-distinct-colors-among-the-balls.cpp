class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> balls;
        unordered_map<int, int> colors;
        int n = queries.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if (balls.find(a) != balls.end()) {
                int prev = balls[a];
                balls[a] = b;
                colors[prev]--;
                if (colors[prev] == 0) {
                    colors.erase(prev);
                }
                cout<<colors.size();
            }
            balls[a]=b;
            colors[b]++;
            ans.push_back(colors.size());
        }
        return ans;
    }
};