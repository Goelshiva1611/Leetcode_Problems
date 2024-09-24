class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string p = strs[0];
        set<string> st;
        string q = "";
        for (int i = 0; i < p.size(); i++) {
            q = q + p[i];
            cout << q;
            st.insert(q);
        }
        int maxi = 0;
        string ans = "";
        for (auto it : st) {
            string p = it;
            for (int i = 1; i < n; i++) {
                if (strs[i].substr(0, p.size()) != p) {
                    return ans;
                }
            }
            ans = p;
        }
        return ans;
    }
};