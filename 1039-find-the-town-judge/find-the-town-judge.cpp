class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, set<int>> mp;
        if(trust.size()==0 && n==1)
        {
            return 1;
        }
        for (int i = 0; i < trust.size(); i++) {
            int v = trust[i][0];
            int u = trust[i][1];

            mp[u].insert(v);
        }
        for (auto it : mp) {
            int a = it.first;
            set<int> st = it.second;
            if (st.size() == n - 1 && st.find(a) == st.end()) {
                bool flag = false;
                for (auto q:st) {
                    if (mp[q].find(a) != mp[q].end()) {
                        flag = true;
                        break;
                    }
                }
                if (flag == false) {
                    return a;
                }
            }
        }
        return -1;
    }
};