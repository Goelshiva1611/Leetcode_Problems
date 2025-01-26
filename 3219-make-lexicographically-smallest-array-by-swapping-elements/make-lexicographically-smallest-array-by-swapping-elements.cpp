class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> v = nums;
        sort(v.begin(), v.end());
        unordered_map<int, int> numtogroup;
        unordered_map<int, list<int>> grouplist;
        int g = 0;
        numtogroup[v[0]] = g;
        grouplist[g].push_back(v[0]);
        for (int i = 1; i < n; i++) {
            if (abs(v[i] - v[i - 1]) > limit) {
                g++;
            }
            numtogroup[v[i]] = g;
            grouplist[g].push_back(v[i]);
        }
        vector<int> result;
        for (int i = 0; i < n; i++) {
            int x = numtogroup[nums[i]];
            result.push_back(*grouplist[x].begin());
            grouplist[x].pop_front();
        }
        return result;
    }
};