class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, int> mp1;
        int j = 0;
        for (int i = 0; i < pattern.size(); i++) {
            string p = "";
            if (j >= s.size())
                return false;
            while (j < s.size()) {
                if (s[j] == ' ')
                    break;
                p = p + s[j];
                j++;
            }
            j++;
            if (mp.find(pattern[i]) != mp.end()) {
                if (mp[pattern[i]] != p)
                    return false;
            } else {
                if (mp1[p] >= 1)
                    return false;
                mp[pattern[i]] = p;
                mp1[p]++;
            }
        }
        if (j < s.size())
            return false;
        return true;
    }
};