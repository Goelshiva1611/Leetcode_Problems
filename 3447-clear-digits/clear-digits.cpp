class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        vector<char> v;
        for (int i = 0; i < n; i++) {
            if (s[i] >= 48 && s[i] <= 57) {
                // is digit
                if (v.size() > 0) {
                    v.pop_back();
                }
            } else {
                v.push_back(s[i]);
            }
        }
        string ans = "";
        for (int i = 0; i < v.size(); i++) {
            ans += v[i];
        }
        return ans;
    }
};