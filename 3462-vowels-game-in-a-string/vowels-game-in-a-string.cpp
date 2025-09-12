class Solution {
public:
    bool doesAliceWin(string s) {
        int t = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                t++;
            }
        }
        return (t == 0) ? false : true;
    }
};