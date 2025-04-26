class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        vector<set<string>> v;
        unordered_map<string, int> mp;
        int n = responses.size();
        for (int i = 0; i < n; i++) {
            vector<string> s = responses[i];
            set<string> st;
            for (int j = 0; j < s.size(); j++) {
                st.insert(responses[i][j]);
            }
            for (auto it : st) {
                mp[it]++;
            }
            v.push_back(st);
        }
        vector<pair<int, string>> answer;
        for (auto it : mp) {

            answer.push_back({it.second, it.first});
        }
        sort(answer.begin(), answer.end(),
             [&](pair<int, string>& a, pair<int, string>& b) {
                 if (a.first == b.first) {
                     return a < b;
                 }
                 return a > b;
             });
        return answer[0].second;
    }
};