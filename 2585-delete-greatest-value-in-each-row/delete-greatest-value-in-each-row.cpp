class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int sum=0;
        vector<int>q;

        for(vector<int>&v: grid)
        {
            sort(v.rbegin(),v.rend());            
        }
        for(int i=0;i<m;i++)
        {
            int t=grid[0][i];
            for(int j=1;j<n;j++)
            {
                if(grid[j][i]>t)
                {
                    cout<<t;
                    t=grid[j][i];
                }
            }
            q.push_back(t);
        }
        for(int i=0;i<q.size();i++)
        {
            sum=sum+q[i];
        }
        return  sum;
    }
};