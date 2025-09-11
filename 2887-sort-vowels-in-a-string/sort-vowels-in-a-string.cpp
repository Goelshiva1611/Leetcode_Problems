class Solution {
public:
    string sortVowels(string s) {
        string t = "";
        vector<char> p;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U') {
                p.push_back(s[i]);
            }
        }
        sort(p.begin(), p.end());
        int x = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U') {
                t.push_back(p[x]);
                x++;
            } else {
                t.push_back(s[i]);
            }
        }
        return t;
    }
};