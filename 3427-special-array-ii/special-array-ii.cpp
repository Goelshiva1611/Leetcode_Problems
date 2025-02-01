class Solution {
public:
    //very precise and clean solution after doing much more formatting and using gernary operator;
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        vector<int> v(nums.size(), 0);
        vector<bool> ans;
        for (int i = 1; i < nums.size(); i++) {
            v[i] = ((nums[i] + nums[i - 1]) % 2 == 0) ? v[i - 1] + 1 : v[i - 1];
        }
        for (int i = 0; i < queries.size(); i++) {
            ans.push_back((v[queries[i][1]] - v[queries[i][0]]) > 0 ? false
                                                                    : true);
        }
        return ans;
    }
};