class Solution {
public:
    unordered_map<char, int> mp;
    int minimumPushes(string word) {
        int n = word.size();
        for (int i = 0; i < n; i++) {
            mp[word[i]]++;
        }
        vector<pair<int, char>> v;
        for (auto it : mp) {
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end());
        int t = 1;
        int p = 0;
        int sum = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            if (p == 8) {
                p = 0;
                t++;
            }
            sum = sum + (t * v[i].first);
            p++;
        }
        return sum;
    }
};