// Clear and clean code here !!!!
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxand = *max_element(nums.begin(), nums.end());
        int i = 0, result = 0;
        while (i < nums.size()) {
            bool flag = true;
            int initial = i;
            while (i < nums.size() && nums[i] == maxand) {
                i++;
                flag = false;
            }
            if (flag == false)
                result = max(result, i - initial);
            else
                i++;
        }
        return result;
    }
};
/*
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
*/