class Solution {
public:
    vector<vector<int>>dp;
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
        int front = sum-stones[i]-solve(stones,i+1,j,sum-stones[i]);
        int back = sum-stones[j]-solve(stones,i,j-1,sum-stones[j]);
        
        int profit = max(front,back);
        return dp[i][j] = profit;
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=stones[i];
        }
        dp.clear();
        dp.resize(1001,vector<int>(1001,-1));
        
        int value =  solve(stones,0,n-1,sum);
        return value;
    }
};