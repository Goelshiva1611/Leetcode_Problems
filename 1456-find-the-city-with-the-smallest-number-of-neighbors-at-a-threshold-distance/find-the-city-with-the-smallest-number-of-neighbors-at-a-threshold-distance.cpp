class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        ios_base::sync_with_stdio(false);

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(vector<int> e: edges){
            dist[e[0]][e[1]]=e[2];
            dist[e[1]][e[0]]=e[2];
        }

        for(int i=0; i<n; i++){
            dist[i][i]=0;
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k]==INT_MAX || dist[j][k]==INT_MAX){
                        continue;
                    }

                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }

        int minCity=INT_MAX;
        int cityNo=-1;
        for(int i=0; i<n; i++){
            int c=0;
            for(int j=0; j<n; j++){
                if(dist[i][j]<=distanceThreshold){
                    c++;
                }
            }

            if(c<=minCity){
                minCity=c;
                cityNo=i;
            }
        }

        return cityNo;
    }
};