class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> rotated(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            rotated.push_back(nums[i]);
        }
        vector<int> answer(n, INT_MAX);
        unordered_map<int, int> mp;
        for (int i = 0; i < 2 * n; i++) {
            if (mp.find(rotated[i]) == mp.end()) {
                mp[rotated[i]] = i;
            } else {
                answer[i % n] = min(answer[i % n], i - mp[rotated[i]]);
                answer[mp[rotated[i]] % n] =
                    min(answer[mp[rotated[i]] % n], i - mp[rotated[i]]);
                mp[rotated[i]] = i;
            }
        }
        vector<int> result;
        for (int i = 0; i < queries.size(); i++) {
            if (answer[queries[i]] == n) {
                result.push_back(-1);
            } else
                result.push_back(answer[queries[i]]);
        }

        return result;
    }
};