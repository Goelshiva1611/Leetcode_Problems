class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<char>& v, int n, int i, string p) {
        if (i >= v.size())
            return 0;
        if (p.size() == n)
            return 1;
        if(dp[i][p.size()]!=-1)
            return dp[i][p.size()];
        string q = p;
        q += v[i];
        int take = solve(v, n, i, q);
        int nottake = solve(v, n, i + 1, p);
        return dp[i][p.size()]=take + nottake;
    }
    int countVowelStrings(int n) {
        vector<char> v;
        dp.resize(6,vector<int>(51,-1));
        v.push_back('a');
        v.push_back('e');
        v.push_back('i');
        v.push_back('o');
        v.push_back('u');
        string p = "";
        return solve(v, n, 0, p);
    }
};