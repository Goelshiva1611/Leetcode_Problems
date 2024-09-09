class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long n = nums.size();
        long long i = 1;
        long long start = nums[0];
        long long ans = 0;
        long long p = 0;
        while (i != n) {
            bool flag = true;
            if (start < nums[i]) {
                ans += (i - p) * start;
                start = nums[i];
                p = i;
                flag = false;
            }
            i++;
            if (i == n && flag == true) {
                ans += (i - p - 1) * start;
                break;
            }
        }
        return ans;
    }
};