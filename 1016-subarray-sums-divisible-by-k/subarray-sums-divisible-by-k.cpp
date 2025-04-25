class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int p = 0;
        for (int i = 0; i < n; i++) {
            p += nums[i];
            nums[i] = p;
        }
        mp[0] = 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int r = nums[i] % k;
            if (r < 0)
                r = k + r;
            if (mp.find(r) != mp.end()) {
                ans += mp[r];
            }
            mp[r]++;
        }
        return ans;
    }
};