class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int j = 0;
        int m = 0;
        int i = 0;
        while (j < n) {
            if (nums[j] == 0) {
                count++;
            }
            while (count > k) {
                cout << j;
                m = max(m, j - i);
                if (nums[i] == 0)
                    count--;
                i++;
            }
            j++;
        }
        m = max(m, j - i);
        return m;
    }
};