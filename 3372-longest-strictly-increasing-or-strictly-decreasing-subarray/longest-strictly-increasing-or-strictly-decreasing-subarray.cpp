class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), count = 1, m = 0;
        if (nums.size() == 1)
            return 1;
        for (int i = 0; i < n - 1;) {
            count = 1;
            while (i + 1 < n && nums[i + 1] - nums[i] < 0) {
                count++;
                i++;
            }
            m = max(m, count);
            count = 1;
            while (i + 1 < n && nums[i + 1] - nums[i] > 0) {
                count++;
                i++;
            }
            if (i + 1 < n && nums[i + 1] - nums[i] == 0) {
                i++;
            }
            m = max(m, count);
        }
        return m;
    }
};