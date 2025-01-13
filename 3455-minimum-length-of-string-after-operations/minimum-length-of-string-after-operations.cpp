class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        int t = 0;
        for (auto it : mp) {
            int freq = it.second;
            if (freq % 2 != 0) {
                t += 1;
            } else {
                t += 2;
            }
        }
        return t;
    }
};