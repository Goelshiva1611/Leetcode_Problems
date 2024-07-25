class Solution {
public:
    int n;
    vector<vector<int>>v;
    unordered_map<int, int> mp;
    int solve(vector<int>& stones, int current, int prev) {
        if (current == n - 1) {
            return true;
        }
        if(v[current][prev]!=-1)
        {
            return v[current][prev];
        }
        bool result = false;
        for (int i = prev - 1; i <= prev + 1; i++) {
            if (i > 0) {
                int nextstone = stones[current] + i;
                if (mp.find(nextstone) != mp.end()) {
                    result = result || solve(stones, mp[nextstone], i);
                }
            }
        }
        return v[current][prev]=result;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        v.clear();
        v.resize(2001,vector<int>(2001,-1));
        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }
        return solve(stones,0,0);
    }
};