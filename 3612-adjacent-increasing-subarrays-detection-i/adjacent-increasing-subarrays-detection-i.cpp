class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            bool f = false;
            if (i >= (nums.size() - 2 * k + 1)) {
                return false;
            }
            for (int x = i; x < nums.size() && x < i + k - 1; x++) {
                if (nums[x + 1] <= nums[x]) {
                    f = true;
                    break;
                }
            }
            if (f == true) {
                continue;
            }

            bool flag = true;
            for (int j = i + k; j < nums.size() && j < i + k + k - 1; j++) {
                if (nums[j + 1] <= nums[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                return true;
            }
        }
        return false;
    }
};