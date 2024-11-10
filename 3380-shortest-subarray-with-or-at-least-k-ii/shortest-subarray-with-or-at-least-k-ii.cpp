class Solution {
public:
    void addthisinvector(vector<int>& v, int num) {
        for (int i = 0; i < 32; i++) {
            if ((num & (1 << i)) != 0) {
                v[i]++;
            }
        }
    }
    void removethisinvector(vector<int>& v, int num) {
        for (int i = 0; i < 32; i++) {
            if ((num & (1 << i)) != 0) {
                v[i]--;
            }
        }
    }
    int decimalnumber(vector<int> v) {
        int num = 0;
        for (int i = 0; i < 32; i++) {
            if (v[i] > 0)
                num = num + (pow(2, i));
        }
        return num;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int result = INT_MAX;
        vector<int> v(32, 0);
        while (j < n) {
            addthisinvector(v, nums[j]);
            while (i <= j && decimalnumber(v) >= k) {
                result = min(result, j - i + 1);
                removethisinvector(v, nums[i]);
                i++;
            }
            j++;
        }
        return (result == INT_MAX) ? -1 : result;
    }
};