class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int V, int src) {
         int m=edges.size();
        vector<vector<pair<int,int>>>adj;
        adj.resize(V+1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<m;i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            int c= edges[i][2];
            adj[a].push_back({b,c});
        }
        pq.push({0,src});
        vector<int>dis(V+1,INT_MAX);
        dis[src]=0;
        while(!pq.empty())
        {
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                if(dis[it.first]>d+it.second)
                {
                    dis[it.first]=d+it.second;
                    pq.push({dis[it.first],it.first});
                }
            }
        }
        int answer=0;
        for(int i=1;i<dis.size();i++)
        {
            answer=max(answer,dis[i]);
        }
        return (answer==INT_MAX)?-1:answer;
        
    }
};


/*
// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
       
    }
};
*/