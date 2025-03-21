class Solution {
public:
    vector<string> findAllRecipes(vector<string>& r,
                                  vector<vector<string>>& ing,
                                  vector<string>& sup) {
        unordered_map<string, vector<string>> mp;
        unordered_map<string, int> indegree;
        set<string> st;
        for (int i = 0; i < sup.size(); i++) {
            st.insert(sup[i]);
        }
        for (int i = 0; i < r.size(); i++) {
            indegree[r[i]] = 0;
        }
        for (int i = 0; i < r.size(); i++) {
            for (int j = 0; j < ing[i].size(); j++) {
                if (st.find(ing[i][j]) == st.end()) {
                    indegree[r[i]]++;
                    mp[ing[i][j]].push_back(r[i]);
                }
            }
        }
        queue<string> qu;
        for (auto it : indegree) {
            if (it.second == 0)
                qu.push(it.first);
        }
        vector<string> answer;
        while (!qu.empty()) {
            string p = qu.front();
            qu.pop();
            answer.push_back(p);
            for (int i = 0; i < mp[p].size(); i++) {
                indegree[mp[p][i]]--;
                if (indegree[mp[p][i]] == 0) {
                    qu.push(mp[p][i]);
                }
            }
        }
        return answer;
    }
};