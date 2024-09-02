class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        cout << n;
        vector<string> p;
        string ans = "";
        string t = "";
        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                reverse(t.begin(), t.end());
                if (count >= 1) {
                    continue;
                }
                if (t[0] != ' ') {
                    p.push_back(t);
                    t = "";
                }
                count++;
                continue;
            }
            count = 0;
            t = t + s[i];
        }
        for (int i = 0; i < p.size(); i++) {
            ans = ans + p[i];
            ans = ans + ' ';
        }
        int q = ans.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ')
                break;
            ans += s[i];
        }
        int x = 0;
        int w = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] != ' ') {
                x = i;
                break;
            }
        }
        for (int i = ans.size() - 1; i >= 0; i--) {
            if (ans[i] != ' ') {
                w = i;
                cout<<w;
                break;
            }
        }
        string a = "";
        for (int i = x; i <= w; i++) {
            a = a + ans[i];
        }
        return a;
    }
};