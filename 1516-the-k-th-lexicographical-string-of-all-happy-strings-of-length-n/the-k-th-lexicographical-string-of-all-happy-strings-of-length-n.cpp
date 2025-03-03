class Solution {
public:
    vector<string> result;
    vector<char> p;
    int t=0;
    void solve(int n, string ans) {
        if(result.size()>t)
        {
            return;            
        }
        if (ans.size() == n) {
            result.push_back(ans);
            return;
        }
        for (int i = 0; i < 3; i++) {
            if (ans.empty()) {
                ans += p[i];
                solve(n, ans);
                ans.pop_back();
            } else {
                if (ans[ans.size() - 1] != p[i]) {
                    ans += p[i];
                    solve(n, ans);
                    ans.pop_back();
                }
            }
        }
    }
    string getHappyString(int n, int k) {
        // happy string a b c waliiii
        t=k;
        string ans = "";
        p.resize(3, ' ');
        char ch = 'a';
        for (int i = 0; i < 3; i++) {
            p[i] = ch;
            ch++;
            cout << p[i];
        }
        solve(n, ans);
        return (result.size() < k) ? "" : result[k - 1];
    }
};