class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        int count = 0;
        long long result = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int t = lower - nums[i];
            int p = upper - nums[i];
            int lower_idx = lower_bound(begin(nums)+i + 1, end(nums), t)-begin(nums);
            int upper_idx = upper_bound(begin(nums)+i + 1, end(nums), p)-begin(nums);
            int x = lower_idx - i-1;
            int y = upper_idx - i -1;

            result += (y - x);
        }
        return result;
    }
};