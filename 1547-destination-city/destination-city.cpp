class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;
        string p = "";
        for (vector<string>& v : paths) {
            if (mp.find(v[1]) == mp.end())
                mp[v[1]] = 0;
            mp[v[0]]++;
        }
        for (auto it : mp) {
            if (it.second == 0) {
                p = it.first;
                break;
            }
        }
        return p;
    }
};