class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>>dp;
    int solve(int i, int prev, int lastprev, vector<int>& nums) {
        if (i >= nums.size()) {
            if (lastprev == -1 && prev == -1)
                return 0;
            return 1;
        }
        if(dp[i][prev+1][lastprev+1]!=-1)
        {
            return dp[i][prev+1][lastprev+1];
        }
        int nottake = solve(i + 1, prev, lastprev, nums) % mod;
        int take = 0;
        if (lastprev == -1 && prev == -1) {
            take = solve(i + 1, nums[i], lastprev, nums) % mod;
        } else if (lastprev == -1) {
            take = solve(i + 1, nums[i], prev, nums) % mod;
        } else {
            if (!(prev == lastprev && prev == nums[i])) {
                take = solve(i + 1, nums[i], prev, nums) % mod;
            }
        }
        return dp[i][prev+1][lastprev+1]=(take + nottake) % mod;
    }
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                nums[i] = 0;
            } else {
                nums[i] = 1;
            }
        }
        dp.resize(nums.size()+1,vector<vector<int>>(3,vector<int>(3,-1)));
        int ans = solve(0, -1, -1, nums);
        return ans % mod;
    }
};