class Solution {
public:
    int dp[1001][1001];
    int solve(vector<int>& stones, int i, int j, int sum){
        if(i>=j){
            return 0;
        }
        if(sum<=0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int choose_front = sum-stones[i]-solve(stones,i+1,j,sum-stones[i]);
        int choose_back = sum-stones[j]-solve(stones,i,j-1,sum-stones[j]);
        
        int profit = max(choose_front,choose_back);
        return dp[i][j] = profit;
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=stones[i];
        }
        memset(dp,-1,sizeof(dp));
        
        int value =  solve(stones,0,n-1,sum);
        return value;
    }
};