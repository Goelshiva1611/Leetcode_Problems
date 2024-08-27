class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {

        unordered_map<int, vector<pair<double, int>>> adj;
        vector<double>result(n,0.0);
        for (int i=0;i<edges.size();i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            double prob=succProb[i];
            cout<<prob;
            adj[a].push_back({prob,b});
            adj[b].push_back({prob,a});
        }
        priority_queue<pair<double ,int>>pq;
        result[start_node]=1.0;
        pq.push({1.0,start_node});
        while (!pq.empty()) {
            double a = pq.top().first;
            int b = pq.top().second;
            cout<<a;
            cout<<b;
            pq.pop();
            if(b==end_node)
            {
                return result[b];
            }
            for (auto &it : adj[b]) {
                cout<<"hello'";
                double newprob=a * it.first;
                int neighbor=it.second;
                cout<<newprob;
                if (result[neighbor] < newprob) {
                    result[neighbor] = newprob;
                    pq.push({newprob,neighbor });
                }
            }
        }
        return result[end_node];
    }
};