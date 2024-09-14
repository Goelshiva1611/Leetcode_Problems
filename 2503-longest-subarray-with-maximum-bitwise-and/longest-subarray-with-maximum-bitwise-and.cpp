class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxand = *max_element(nums.begin(), nums.end());
        int result = 0;
        int i = 0;
        while (i < n) {
            int a = nums[i];
            if (a != maxand) {
                i++;
                continue;
            }
            int q = i;
            bool flag = true;
            for (int j = q; j < n; j++) {
                if (nums[j] != maxand) {
                    i = j;
                    flag = false;
                    break;
                }
            }
            if (flag == false) {
                result = max(result, i - q);
            } else {
                result = max(result, n - q);
                break;
            }
        }
        return result;
    }
};