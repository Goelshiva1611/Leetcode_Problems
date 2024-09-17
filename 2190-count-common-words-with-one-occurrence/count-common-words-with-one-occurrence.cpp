class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp1, mp2;
        int i = 0, j = 0, count = 0, n = words1.size(), m = words2.size();
        while (i < n)
            mp1[words1[i++]]++;
        while (j < m)
            mp2[words2[j++]]++;
        for (auto it : mp1)
            if (mp2.find(it.first) != mp2.end() && it.second == 1 &&
                mp2[it.first] == 1)
                count++;
        return count;
    }
};