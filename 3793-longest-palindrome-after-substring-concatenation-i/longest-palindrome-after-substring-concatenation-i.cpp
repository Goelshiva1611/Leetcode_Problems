class Solution {
public:
    int maximum = 0;
    bool ispalindrome(string p) {
        int i = 0;
        int j = p.size() - 1;
        while (i <= j) {
            if (p[i] != p[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void checkinside(string p, string t) {
        for (int i = 0; i < t.size(); i++) {
            for (int j = i; j <= t.size(); j++) {
                string news = t.substr(i, j - i);
                string final = p + news;
                if (ispalindrome(final)) {
                    int n = final.size();
                    maximum = max(maximum, n);
                }
            }
        }
    }
    int longestPalindrome(string s, string t) {
        int n = s.size();
        int m = t.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j <= n; j++) {
                string s1 = s.substr(i, j - i);
                checkinside(s1, t);
            }
        }
        return maximum;
    }
};