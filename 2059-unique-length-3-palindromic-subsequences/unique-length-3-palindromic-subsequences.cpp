class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, int> freq;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            freq[s[i]]++;
        }
        int i = 0;
        int j = i + 1;
        int t = 0;
        while (j < n) {

            while (freq[s[i]] > 1 && j < n) {
                if (s[i] == s[j])
                    freq[s[j]]--;
                j++;
            }
            j--;
            unordered_set<char> st;
            for (int p = i + 1; p < j; p++) {
                st.insert(s[p]);
            }
            t += st.size();
            i++;
            j = i + 1;
        }
        return t;
    }
};