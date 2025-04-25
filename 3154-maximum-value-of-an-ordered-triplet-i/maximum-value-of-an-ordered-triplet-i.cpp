class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long  maxv = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long t = nums[i] - nums[j];
                for (int k = j + 1; k < n; k++) {
                    maxv = max(maxv, nums[k] * t);
                }
            }
        }
        return (maxv >= 0) ? maxv : 0;
    }
};