
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int m=points[0].size();
        vector<long long int>  prev(m);
        for(int i=0;i<m;i++)
        {
            prev[i]=points[0][i];
        }
        for(int i=1;i<n;i++)
        {
            vector<long long int>  left(m,0);
            vector<long long int>  right(m,0);
            vector<long long int>  current(m);
            left[0]=prev[0];
            for(int j=1;j<m;j++)
            {
                left[j]=max(left[j-1]-1,prev[j]);
            }
            right[m-1]=prev[m-1];
            for(int j=m-2;j>=0;j--)
            {
                right[j]=max(right[j+1]-1,prev[j]);
            }
            for(int j=0;j<m;j++)
            {
                current[j]=points[i][j]+max(left[j],right[j]);
            }
            prev=current;

        }
        return *max_element(begin(prev),end(prev));        
    }
};