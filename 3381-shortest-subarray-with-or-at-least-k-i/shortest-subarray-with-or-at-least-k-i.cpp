class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int m = INT_MAX;
        for (int i = 0; i < n; i++) {
            int first = nums[i];
            if (first >= k) {
                m = min(m, 1);
            }
            for (int j = i + 1; j < n; j++) {
                first = first | nums[j];
                if (first >= k) {
                    m = min(m, j - i + 1);
                }
            }
        }
        if (m == INT_MAX) {
            return -1;
        }
        return m;
    }
};