class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        for(int i=0;i<grid.size();i++)
        {
            sort(grid[i].rbegin(),grid[i].rend());
        }
        int m=grid[0].size();
        vector<int>v;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<limits[i];j++)                      
            {
                v.push_back(grid[i][j]);
            }
        }
        sort(v.rbegin(),v.rend());
        long long sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=v[i];
        }
        return sum;
    }
};