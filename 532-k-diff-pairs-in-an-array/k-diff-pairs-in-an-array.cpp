class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        int count = 0;
        set<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            int j = 0;
            while (mp.find(nums[i]) != mp.end()) {
                if (st.find({mp[nums[i]][j], nums[i]}) == st.end() &&
                    st.find({nums[i], mp[nums[i]][j]}) == st.end()) {
                    st.insert({mp[nums[i]][j], nums[i]});
                }
                mp[nums[i]].pop_back();
                if (mp[nums[i]].size() == 0) {
                    mp.erase(nums[i]);
                }
                j++;
            }
            int first = nums[i] - k;
            int second = nums[i] + k;
            mp[first].push_back(nums[i]);
            mp[second].push_back(nums[i]);
        }
        return st.size();
    }
};