
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long long sum = 0;
        int i = 0;
        int j = 0;
        long long m = 0;
        unordered_map<int, int> mp;
        while (j < nums.size()) {
            mp[nums[j]]++;
            while (mp[nums[j]] > 1) {
                mp[nums[i]]--;
                sum -= nums[i];
                i++;
            }
            bool flag = true;
            if (j - i + 1 == k) {
                sum += nums[j];
                m = max(m, sum);
                flag = false;
                sum -= nums[i];
                mp[nums[i]]--;
                i++;
            }
            if (flag == true)
                sum += nums[j];
            j++;
        }
        return m;
    }
};