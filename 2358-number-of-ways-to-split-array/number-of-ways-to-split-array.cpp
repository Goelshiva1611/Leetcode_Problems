class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long int> prefixsum;
        long long int sum = nums[0];
        long long int totalsum = 0;
        prefixsum.push_back(sum);
        for (int i = 0; i < n; i++) {
            totalsum += nums[i];
        }
        for (int i = 1; i < n; i++) {
            sum += nums[i];
            prefixsum.push_back(sum);
        }
        int t = 0;
        for (int i = 0; i < n - 1; i++) {
            if (prefixsum[i] - (totalsum - prefixsum[i]) >= 0) {
                t++;
            }
        }
        return t;
    }
};