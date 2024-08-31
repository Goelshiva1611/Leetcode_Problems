class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
    
        vector<vector<int>>adj(n);
        for(int i=0;i<roads.size();i++)
        {
            int u=roads[i][0];
            int v=roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({adj[i].size(),i});
        }
        sort(v.rbegin(),v.rend());
        int t=n;
        unordered_map<int ,int>mp;
        for(int i=0;i<v.size();i++)
        {
            mp[v[i].second]=t;
            t--;
        }
        long long int sum=0;
        for(int i=0;i<roads.size();i++)
        {
            int a=roads[i][0];
            int b=roads[i][1];
            sum+=mp[a]+mp[b];
        }
        return sum;

    }
};