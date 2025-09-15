class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        set<int> st;
        for (int i = 0; i < brokenLetters.size(); i++) {
            st.insert(brokenLetters[i]);
        }
        int n = text.size(), answer = 0, s = 0;
        for (int i = 0; i < n; i++) {
            if (st.find(text[i]) != st.end()) {
                while (i < n && text[i] != ' ')
                    i++;
                answer++;
            }
            if (text[i] == ' ')
                s++;
        }
        return s + 1 - answer;
    }
};