class Solution {
public:
    vector<int> partitionLabels(string nums) {
        unordered_map<char, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        int t = -1;
        vector<int> v;
        unordered_map<char, int> mp1;
        for (int i = 0; i < n; i++) {
            mp1[nums[i]]++;
            mp[nums[i]]--;
            if (mp[nums[i]] == 0) {
                mp1.erase(nums[i]);
                if (mp1.empty()) {
                    v.push_back(i - t);
                    t = i;
                }
            }
        }
        return v;
    }
};