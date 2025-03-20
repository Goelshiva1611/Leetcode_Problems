class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        bool flag = true;
        int sum = 0;
        for (auto it : mp) {
            if (it.first >= 0) {
                flag = false;
                sum += it.first;
            }
        }
        if (flag == false) {
            return sum;
        }
        sort(nums.rbegin(), nums.rend());
        return nums[0];
    }
};