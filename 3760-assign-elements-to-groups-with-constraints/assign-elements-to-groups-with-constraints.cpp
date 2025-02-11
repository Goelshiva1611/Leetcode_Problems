class Solution {
public:
    vector<int> assignElements(vector<int>& g, vector<int>& e) {
        int n = g.size() ;
        int m = e.size() ;
        map<int , int> map ;
        for(int i = 0 ; i < m ; i++) {
            if( map.find(e[i]) == map.end() )
             map[e[i]] = i ;
        }

        vector<int> v ;

        for(int i = 0 ; i < n ; i++) {
            int ans = INT_MAX ;
            for(int j = 1 ; j*j<=(g[i]) ;j++) {
                if( g[i] % j == 0 && map.find(j) != map.end()) {
                    ans = min(map[j] , ans) ;
                } 

                int div = g[i] / j ;
                if( g[i] % div == 0 && map.find(div) != map.end()) {
                    ans = min(map[div] , ans) ;
                } 
            }

            if( ans == INT_MAX)  ans = -1 ;
            v.push_back(ans) ;
        }

        return v ;

    }
        
};