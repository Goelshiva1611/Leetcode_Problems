class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> vv;
        int size = original.size();
        if (size != n * m) {
            return {};
        }
        int t = 0;
        while (m) {
            vector<int> v;
            for (int i = t; i < t + n; i++) {
                v.push_back(original[i]);
            };
            vv.push_back(v);
            t += n;
            m--;
        }
        return vv;
    }
};