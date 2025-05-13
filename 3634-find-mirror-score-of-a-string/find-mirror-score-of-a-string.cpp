class Solution {
public:
    long long calculateScore(string s) {
        long long total = 0;
        unordered_map<int, stack<int>> mp;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char b = s[i];
            int p = b - 97;
            if (mp[25 - p].size() >= 1) {
                total += i - mp[25 - p].top();
                mp[25 - p].pop();
            } else
                mp[p].push(i);
            if (mp[25 - p].size() == 0)
                mp.erase(25 - p);
        }
        return total;
    }
};