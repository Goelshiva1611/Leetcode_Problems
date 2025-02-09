class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long ,long long>mp;
        for (int i = 0; i < n; i++) {
            int t=nums[i];
            string p=to_string(nums[i]);
            reverse(p.begin(),p.end());
            mp[t-stoi(p)]++;
        }
        long long  ans = 0;
        for (auto it : mp) {
            ans += (it.second) * (it.second - 1) / 2;
        }
        int mod=1e9+7;
        return ans%mod;
    }
};