class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        int v = 0;
        int c = 0;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        for (auto it : mp) {
            if (it.first == 'a' || it.first == 'e' || it.first == 'i' ||
                it.first == 'o' || it.first == 'u') {
                v = max(it.second, v);
            } else {
                c = max(c, it.second);
            }
        }
        return v + c;
    }
};