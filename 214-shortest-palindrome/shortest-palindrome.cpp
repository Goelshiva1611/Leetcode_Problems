class Solution {
public:
    string shortestPalindrome(string s) {
        string t = process(s);
        int n = t.length(), center = 0, right = 0;
        int* palin = new int[n];
        for (int i = 1; i < n - 1; i++) {
            int i_mirror = 2 * center - i;
            palin[i] = (right > i) ? min(palin[i_mirror], right - i) : 0;
            while (t[i + palin[i] + 1] == t[i - palin[i] - 1])
                palin[i]++;
            if (i + palin[i] > right) {
                center = i;
                right = i + palin[i];
            }
        }
        int pos;
        for (int i = n - 2; i; i--) {
            if (i - palin[i] == 1) {
                pos = palin[i];
                break;
            }
        }
        string tail = s.substr(pos); 
        reverse(tail.begin(), tail.end());
        return tail + s;
    }
private:
    string process(string& s) {
        int n = s.length();
        string t(2 * n + 3, '#');
        t[0] = '$'; t[2 * n + 2] = '%';
        for (int i = 0; i < n; i++)
            t[2 * (i + 1)] = s[i];
        return t;
    }
};