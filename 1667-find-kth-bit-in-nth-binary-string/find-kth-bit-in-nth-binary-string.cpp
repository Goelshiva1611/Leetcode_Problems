class Solution {
public:
    string invert(string s) {
        string p;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                p += '1';
            } else {
                p += '0';
            }
        }
        return p;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        string p = "";
        if (n == 1 && k == 1) {
            return '0';
        }
        for (int i = 1; i < n; i++) {
            string x = invert(s);
            reverse(x.begin(), x.end());
            p = s + "1" + x;
            s = p;
        }
        return p[k - 1];
    }
};