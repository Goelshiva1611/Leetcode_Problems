class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(),
             [&](string& a, string& b) { return a.size() < b.size(); });
        set<string> st;
        for (int i = 0; i < folder.size(); i++) {
            string t = folder[i];

            cout << t;
            cout << endl;
            if (st.empty())
                st.insert(t);
            else {
                int q = 1;
                bool flag = false;
                while (q < t.size()) {
                    while (q < t.size() && t[q] != '/') {
                        q++;
                    }
                    q++;
                    string p = t.substr(0, q - 1);
                    if (st.find(p) != st.end()) {
                        flag = true;
                        break;
                    }
                }
                if (flag == false)
                    st.insert(t);
            }
        }
        vector<string> v;
        for (auto it : st) {
            v.push_back(it);
        }
        return v;
    }
};