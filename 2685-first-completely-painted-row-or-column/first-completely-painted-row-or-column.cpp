class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> mp;
        unordered_map<int, int> mp1;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < m * n; i++) {
            mp1[i] = 0;
        }
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                mp[mat[i][j]] = {i, j};
            }
        }
        for (int i = 0; i < arr.size(); i++) {
            auto it = mp[arr[i]];
            int r = it.first;
            int c = it.second;
            mp1[r]++;
            mp1[n + c]++;
            if (mp1[r] == m || mp1[n + c] == n)
                return i;
        }
        return 0;
    }
};