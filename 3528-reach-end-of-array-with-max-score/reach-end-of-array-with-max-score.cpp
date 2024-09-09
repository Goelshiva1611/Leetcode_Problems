class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0;
        int curr = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ans += curr;
            curr = max(curr, nums[i]);
        }
        return ans;
    }
};