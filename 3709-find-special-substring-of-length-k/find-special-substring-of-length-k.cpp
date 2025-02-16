class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size();
        set<char> st;
        for (int i = 0; i <= n - k; i++) {
            st = {};
            string newstring = s.substr(i, k);
            for (int j = 0; j < newstring.size(); j++) {
                st.insert(newstring[j]);
            }
            if ((st.size() == 1)) {
                if (i == 0) {
                    if (i + k < n && s[i + k] != *st.begin()) {
                        return true;
                    }
                    if (i + k >= n) {
                        return true;
                    }
                } else if (i + k >= n) {
                    if (s[i - 1] != *st.begin()) {
                        return true;
                    }
                } else {
                    if (i + k < n && s[i + k] != *st.begin() &&
                        s[i - 1] != *st.begin()) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};