//Recursion + Memoization - ACCEPTED
class Solution {
public:
    /*
        dp[i][j][k] =  number of unique ways to cut mat[i..m-1][j..n-1] into k pieces so that each piece has atleast one apple , 
        
        apples[i][j] = number of apples on mat[i..m-1][j..n-1]. 
        Because after cutting, we always have the down-right corner of the matrix left, so this setting is valid.
    */
    
    int m, n;
    int apples[55][55];
    vector<vector<vector<int>>>dp;
    long long MOD = 1e9 + 7;
    
    int solve(int i, int j, int k) {
        
        if(apples[i][j] < k)
            return 0;
        
        if(k == 1) {
            return (apples[i][j] >= 1) ? 1 : 0;
        }
        
         
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        int ans= 0;
        
        for (int h = i + 1; h < m; h++) {
            
            if (apples[i][j] - apples[h][j] > 0 && apples[h][j] >= k - 1) {
                
                ans = (ans% MOD + solve(h, j, k - 1) % MOD) % MOD;
                
            }
        }

        for (int v = j + 1; v < n; v++) {
            
            if (apples[i][j] - apples[i][v] > 0 && apples[i][v] >= k - 1) {
                ans = (ans% MOD + solve(i, v, k - 1) % MOD) % MOD;
            }
        }

        return dp[i][j][k]=ans;
        
    }
    
    int ways(vector<string>& pizza, int k) {
        m = pizza.size();
        n = pizza[0].length();
        
        memset(apples, 0, sizeof(apples));
        
        for(int i = m-1; i>=0; i--) {
            
            for(int j = n-1; j>=0; j--) {
                
                apples[i][j] = apples[i][j+1];
                
                for(int l = i; l<m; l++) {
                    apples[i][j] += (pizza[l][j]=='A');
                }
                
            }
            
        }
        dp.clear();
        dp.resize(55,vector<vector<int>>(55,vector<int>(11,-1)));
        
        return solve(0, 0, k);
        
    }
};