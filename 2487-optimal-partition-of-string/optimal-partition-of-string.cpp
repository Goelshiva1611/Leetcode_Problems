class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int count = 0;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
            if (mp[s[i]] > 1) {
                count++;
                unordered_map<char, int> mp1;
                mp = mp1;
                mp[s[i]]++;
            }
        }
        if (mp.size() >= 1) {
            count++;
        }
        if (count == 0) {
            return 1;
        }
        return count;
    }
};