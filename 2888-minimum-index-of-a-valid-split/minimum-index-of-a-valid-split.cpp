class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        bool flag = false;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] > n / 2)
                flag = true;
        }
        if (flag == false)
            return -1;
        unordered_map<int, int> mp1;
        for (int i = 0; i < n; i++) {
            mp1[nums[i]]++;
            if (mp[nums[i]] > n / 2)
                if (abs(mp[nums[i]] - mp1[nums[i]]) * 2 > n - i - 1 &&
                    mp1[nums[i]] * 2 > i + 1)
                    return i;
        }
        return -1;
    }
};