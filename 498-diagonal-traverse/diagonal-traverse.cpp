class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>> mp;
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                int t=(i + j);
                mp[t].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        for (auto it : mp) {
            if (it.first % 2 == 0) {
                reverse(it.second.begin(), it.second.end());
                
                for (auto p : it.second)
                    ans.push_back(p);
            } else {
                for (auto p : it.second)
                    ans.push_back(p);
            }
        }
        return ans;
    }
};