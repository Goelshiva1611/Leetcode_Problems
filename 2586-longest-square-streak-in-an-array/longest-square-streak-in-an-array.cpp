class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int x = (int)sqrt(nums[i]);
            if (x * x == nums[i] && mp.find(x) != mp.end()) {
                mp[nums[i]] = mp[sqrt(nums[i])] + 1;
            } else {
                if(mp.find(nums[i])==mp.end())
                    mp[nums[i]]++;
                
            }
        }
        int m = 0;
        for (auto it : mp) {
            m = max(m, it.second);
        }
        if (m == 1)
            return -1;
        return m;
    }
};