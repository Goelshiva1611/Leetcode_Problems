class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }

        int v = 0;
        int c = 0;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if ((word[i] >= 97 && word[i] <= 122) ||
                (word[i] >= 65 && word[i] <= 90) ||
                (word[i] >= 48 && word[i] <= 57)) {
                if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
                    word[i] == 'o' || word[i] == 'u' || word[i] == 'A' ||
                    word[i] == 'E' || word[i] == 'I' || word[i] == 'O' ||
                    word[i] == 'U') {
                    v++;
                } else if ((word[i] >= 97 && word[i] <= 122) ||
                           (word[i] >= 65 && word[i] <= 90)) {
                    c++;
                }
            } else {
                return false;
            }
        }
        if (v == 0 || c == 0) {
            return false;
        }
        return true;
    }
};