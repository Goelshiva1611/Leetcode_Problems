class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int count = 0;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            string p = "";
            int c = 0;
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++) {
                p += word[j];
                if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' ||
                    word[j] == 'o' || word[j] == 'u') {
                    mp[word[j]]++;
                } else {
                    c++;
                }
                if (mp.size() < 5) {
                    continue;
                }
                if (c == k) {
                    count++;
                }
            }
        }
        return count;
    }
};