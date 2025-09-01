class Solution {
public:
    #define P pair<double, int>
    double maxAverageRatio(vector<vector<int>>& arr, int x) {
        int n=arr.size();
        priority_queue<P>pq; 
        for(int i=0;i<n;i++){
            double cpr=(double)arr[i][0]/arr[i][1];
            double npr=(double)(arr[i][0]+1)/(arr[i][1]+1);
            double del=npr-cpr;
            pq.push({del,i});
        }
        while(x--){ 
            auto curr=pq.top(); 
            pq.pop();
            double del=curr.first;
            int idx=curr.second;
            arr[idx][0]++; 
            arr[idx][1]++; 
            double cpr=(double)arr[idx][0]/arr[idx][1];
            double npr=(double)(arr[idx][0]+1)/(arr[idx][1]+1);
            del=npr-cpr;
            pq.push({del,idx}); 
        }
        double ans=0.0;
        for(int i=0;i<n;i++){
            ans+=(double)arr[i][0]/arr[i][1];
        }
        return ans/n;
    }
};