class Solution {
public:
    int mp = 0;
    void solve(vector<int> nums, int i, int& count, int p) {
        if (i >= nums.size()) {
            return;
        }
        int q = p | nums[i];
        if (q == mp) {
            count++;
        }
        solve(nums, i + 1, count, q);
        solve(nums, i + 1, count, p);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int p = 0;
        for (int i = 0; i < n; i++) {
            p = p | nums[i];
        }
        mp = p;
        int ans = 0;
        solve(nums, 0, ans, 0);
        return ans;
    }
};