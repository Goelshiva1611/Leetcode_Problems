class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string q = "", ans = "";
        set<string> st;
        for (int i = 0; i < strs[0].size(); i++) {
            q = q + strs[0][i];
            st.insert(q);
        }
        for (auto it : st) {
            string p = it;
            for (int i = 1; i < strs.size(); i++)
                if (strs[i].substr(0, p.size()) != p)
                    return ans;
            ans = p;
        }
        return ans;
    }
};