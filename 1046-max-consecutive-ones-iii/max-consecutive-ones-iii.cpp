class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0;
        int j = 0;
        int i = 0;
        int m = 0;
        int t = 0;
        int n = nums.size();
        for (int p = 0; p < n; p++) {
            if (nums[p] == 0) {
                t++;
            }
        }
        if (t <= k) {
            return n;
        }
        while (j < nums.size()) {
            if (nums[j] == 0) {
                count++;
            }
            if (count > k) {
                m = max(m, j - i);
                while (count != k) {
                    if (nums[i] == 0) {
                        count--;
                    }
                    i++;
                }
            }
            j++;
        }
        int r = 0;
        for (int y = i; y < j; y++) {
            if (nums[y] == 0) {
                r++;
            }
        }
        if (r <= k) {
            m = max(m, j - i);
        }
        return m;
    }
};