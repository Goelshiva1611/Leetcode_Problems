class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        vector<vector<int>>ans;
        ans.resize(grid.size(),vector<int>(grid.size(),0));
        if(grid.size()==1)
        {
            return grid;
        }
        int n=grid.size();
        for (int i = 0; i < n; i++) {
            vector<int> v;
            for (int j = 0; j < n - i; j++) {
                v.push_back(grid[i + j][j]);
            }
            sort(v.rbegin(), v.rend());
            for (int j = 0; j < v.size(); j++) {
                ans[i + j][j] = v[j];
            }
        }
        cout<<"xhjks";
        for (int i = 0; i <n-1; i++) {
            vector<int> v;
            for (int j = i+1; j <=n-1; j++) {
                v.push_back(grid[j-i-1][j]);
            }
            sort(v.begin(), v.end());
            int t=0;
            for (int j = i+1; j <=n-1; j++) {
                ans[j-i-1][j] = v[t];
                t++;
            }
        }
        return ans;
    }
};