class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        vector<pair<bool, pair<int, int>>> v;
        int n = nums.size();
        int q = queries.size();
        v.resize(n,{false,{0,0}});

        vector<bool> ans;
        v[0] = {true, {1, 0}};
        for (int i = 1; i < n; i++) {
            if ((nums[i] + nums[i - 1]) % 2 == 0) // same parity
            {
                v[i] = {false,
                        {v[i - 1].second.first, v[i - 1].second.second + 1}};
            } else {
                v[i] = {true,
                        {v[i - 1].second.first + 1, v[i - 1].second.second}};
            }
            cout<<v[i].second.first;
            cout<<v[i].second.second;
            cout<<endl;
        }

        for (int i = 0; i < q; i++) {
            // now first query
            int a = queries[i][0]; // start
            int b = queries[i][1]; // end
            int diff = v[b].second.second - v[a].second.second;
            if (diff > 0) {
                ans.push_back(false);
            } else {
                ans.push_back(true);
            }
        }
        return ans;
    }
};