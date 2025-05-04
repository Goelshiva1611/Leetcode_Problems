class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& nums) {
        map<pair<int, int>, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int a = nums[i][0];
            int b = nums[i][1];
            if (mp.find({a, b}) != mp.end()) {
                mp[{a, b}]++;
            } else {
                if (mp.find({b, a}) != mp.end()) {
                    mp[{b, a}]++;
                } else {
                    mp[{a, b}]++;
                }
            }
        }
        int count = 0;
        for (auto it : mp) {
            count += (it.second * (it.second - 1) / 2);
        }
        return count;
    }
};