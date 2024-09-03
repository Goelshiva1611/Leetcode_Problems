class Solution {
public:
    int getLucky(string s, int k) {
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n; i++) {
            ans += to_string(s[i] - 'a' + 1);
        }
        int t = 0;
        int p = ans.size();
        string x = ans;
        while (k) {
            t = 0;
            for (int i = 0; i < p; i++) {
                t += x[i] - '0';
            }
            x = to_string(t);
            p = x.size();
            k--;
        }
        return t;
    }
};