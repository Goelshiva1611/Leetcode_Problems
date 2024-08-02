class Solution {
public:
    int n;
    vector<vector<int>> v;
    int solve(string& s, int i, int previous) {
        if (i >= n) {
            return 0;
        }
        if (v[i][previous] != -1) {
            return v[i][previous];
        }
        int flip = INT_MAX;
        int noflip = INT_MAX;
        if (s[i] == '1') {
            if (previous == 0) {
                flip = 1 + solve(s, i + 1, 0);
                noflip = solve(s, i + 1, 1);
            } else {
                noflip = solve(s, i + 1, 1);
            }
        } else {
            if (previous == 1) {
                flip = 1 + solve(s, i + 1, 1);
            } else {
                flip = 1 + solve(s, i + 1, 1);
                noflip = solve(s, i + 1, 0);
            }
        }
        return v[i][previous] = min(flip, noflip);
    }
    int minFlipsMonoIncr(string s) {
        v.clear();
        n = s.size();
        v.resize(n + 1, vector<int>(2, -1));
        return solve(s, 0, 0);
    }
};