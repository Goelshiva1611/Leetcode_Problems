class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int m = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            m = max(m, nums[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == m) {
                nums[i] = 1;
            } else {
                nums[i] = 0;
            }
        }
        int j = 0;
        int i = 0;
        long long sum = 0;
        long long count = 0;
        while (j < nums.size()) {
            sum += nums[j];
            while (sum > k - 1) {
                sum -= nums[i];
                i++;
            }
            count += j - i + 1;
            j++;
        }
        long long t = (long long)n * (n + 1) / 2;
        return t - count;
    }
};