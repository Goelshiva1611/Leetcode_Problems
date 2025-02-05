class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        map<char, vector<int>> mp1;
        if (s1 == s2) {
            return true;
        }
        if (s1.size() != s2.size()) {
            return false;
        }
        for (int i = 0; i < s1.size(); i++) {
            mp1[s1[i]].push_back(i);
        }
        int n = s1.size();
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                // now
                for (int j = 0; j < mp1[s2[i]].size(); j++) {
                    swap(s1[i], s1[mp1[s2[i]][j]]);
                    if (s1 == s2) {
                        flag == true;
                        return true;
                    }else
                    {
                        swap(s1[i], s1[mp1[s2[i]][j]]);
                    }
                }
                if (flag == false) {
                    return false;
                }
            }
        }
        return true;
    }
};

/*
set<t> st1, st2;
        int n = s1.size();
        unordered_map<char, int> mp1, mp2;
        if (s1.size() != s2.size())
            return false;
        for (int i = 0; i < n; i++) {
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        for (auto it : mp1)
            st1.insert({it.first, it.second});
        for (auto it : mp2)
            st2.insert({it.first, it.second});
        return (st1 == st2) ? true : false;
*/