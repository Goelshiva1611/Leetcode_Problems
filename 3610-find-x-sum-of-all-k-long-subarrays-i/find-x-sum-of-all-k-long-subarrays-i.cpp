class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int anslength = n - k + 1;
        vector<int> ans;
        for (int i = 0; i < n - k + 1; i++) {
            set<int> st;
            int sum = 0;
            unordered_map<int, int> mp;
            for (int j = i; j < i + k; j++) {
                sum += nums[j];
                mp[nums[j]]++;
                st.insert(nums[j]);
            }
            if (st.size() < x) {
                ans.push_back(sum);
            } else {
                vector<pair<int, int>> v;
                for (auto& it : mp)
                    v.push_back({it.second, it.first});
                sort(v.begin(), v.end(),
                     [&](pair<int, int> a, pair<int, int> b) {
                         if (a.first == b.first) {
                             return a.second > b.second;
                         }
                         return a.first > b.first;
                     });
                int t = 0;
                for (int q = 0; q < x; q++)
                    t += v[q].first * v[q].second;
                ans.push_back(t);
            }
        }
        return ans;
    }
};