class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        long long  p = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % modulo == k)
                nums[i] = 1;
            else
                nums[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            p += nums[i];
            nums[i] = p;
        }
        mp[0] = 1;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int r = nums[i] % modulo;
            int r2 = (r - k + modulo) % modulo;

            if (mp.find(r2) != mp.end()) {
                ans += mp[r2];
            }
            mp[r]++;
        }
        return ans;
    }
};