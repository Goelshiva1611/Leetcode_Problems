class Solution {
public:
vector<vector<int>> v;
    int solve(string &s1, string &s2, int i, int j) {
        if (i >= s1.length() || j >= s2.length()) {
            return 0;
        }
        if(v[i][j]!=-1)
        {
            return v[i][j];
        }
        if (s1[i] == s2[j]) {
            return v[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
        }

        return v[i][j] = max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
    } 
    int longestPalindromeSubseq(string s) {
        v.clear();
        v.resize(1001,vector<int>(1001,-1));
        string s1="";
        for(int i=s.size();i>=0;i--)
        {
            s1+=s[i];
        }
        return solve(s,s1,0,0);
    }
};