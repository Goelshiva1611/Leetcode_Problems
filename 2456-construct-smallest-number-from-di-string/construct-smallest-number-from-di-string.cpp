class Solution {
public:
    set<string> result;
    vector<int> v;

    void solve(string p, string ans, int i) {
        if (i == p.size()) {
            cout << ans;
            result.insert(ans);
            return;
        }
        for (int j = 1; j < 10; j++) {
            char newchar = p[i];
            if (v[j] == 1)
                continue;
            if ((newchar == 'I' && j > (ans[ans.size() - 1] - '0')) ||
                (newchar == 'D' && (ans[ans.size() - 1] - '0') > j)) {
                v[j] = 1;
                ans += to_string(j);
                solve(p, ans, i + 1);
                v[j] = 0;
                ans.pop_back();
            } 
        }
    }
    string smallestNumber(string pattern) {

        v.resize(10, 0);
        int n = pattern.size();
        for (int i = 1; i <= 9; i++) {
            string ans = "";
            v[i] = 1;
            ans += to_string(i);
            cout << ans;
            solve(pattern, ans, 0);
            v[i] = 0;
        }
        return *result.begin();
    }
};