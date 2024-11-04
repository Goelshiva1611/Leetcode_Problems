class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size() - 1;
        int i = 0;
        if (sentence[i] != sentence[n]) {
            return false;
        }
        char ch;
        while (i < n) {
            while (i < n && sentence[i] != ' ') {
                ch = sentence[i];
                i++;
            }
            i++;
            if (i <= n && ch != sentence[i]) {
                cout << ch;
                return false;
            }
        }
        return true;
    }
};