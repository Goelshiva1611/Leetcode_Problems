class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int q=points[0][0];
        int r=points[0][1];
        int time=0;
        for(int i=1;i<n;i++)
        {
            int a=points[i][0];
            int b=points[i][1];
            time+=max(abs(q-a),abs(r-b));
            q=a;
            r=b;
        }
        return time;
    }
};